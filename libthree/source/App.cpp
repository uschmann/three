#include "three.h"

App *App::INSTANCE = 0;

App::App() {
    this->init();
}

void App::init() {
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();

    SDL_SetEventFilter(App::FilterEvents);
    romfsInit();

    // this->surface = SDL_SetVideoMode(400, 240 * 2, 32, SDL_SWSURFACE | SDL_DUALSCR | SDL_FITHEIGHT);
    this->surface = SDL_SetVideoMode(400, 240 * 2, 32, SDL_SWSURFACE | SDL_CONSOLEBOTTOM | SDL_FITHEIGHT);
    this->isRunning = true;
    this->topScreen = new Screen();
    this->bottomScreen = new BottomScreen();
    this->assetManager = new AssetManager();
    this->httpService = new HttpService();
}

void App::deinit() {
    SDL_Quit();
}

App *App::getInstance() {
    if(!App::INSTANCE) {
        App::INSTANCE = new App();
    }
    return App::INSTANCE;
}

SDL_Surface *App::getSurface() {
    return this->surface;
}

void App::startController(Controller *controller) {
    this->currentController = controller;
    this->currentController->onCreate(this);
}

int App::FilterEvents(const SDL_Event *event) {
    return App::getInstance()->processEvent(event);
}

int App::processEvent(const SDL_Event *event) {
    switch(event->type) {
        case SDL_MOUSEBUTTONDOWN:
            TouchEvent touchDownEvent;
            touchDownEvent.screenX = event->button.x;
            touchDownEvent.screenY = event->button.y;
            touchDownEvent.targetX = event->button.x;
            touchDownEvent.targetY = event->button.y;
            printf("Mouse DOWN on (%d,%d)\n", event->button.x, event->button.y);
            break;
        case SDL_MOUSEMOTION:
            TouchMoveEvent touchMoveEvent;
            touchMoveEvent.screenX = event->motion.x;
            touchMoveEvent.screenY = event->motion.y;
            touchMoveEvent.targetX = event->motion.x;
            touchMoveEvent.targetY = event->motion.y;
            touchMoveEvent.deltaX = event->motion.xrel;
            touchMoveEvent.deltaY = event->motion.yrel;
            printf("Mouse moved to (%d,%d)\n", event->motion.x, event->motion.y);
            printf("Mouse moved by (%d,%d)\n", event->motion.xrel, event->motion.yrel);
            break;
        case SDL_MOUSEBUTTONUP:
            TouchEvent touchUpEvent;
            touchUpEvent.screenX = event->button.x;
            touchUpEvent.screenY = event->button.y;
            touchUpEvent.targetX = event->button.x;
            touchUpEvent.targetY = event->button.y;
            printf("Mouse UP on (%d,%d)\n", event->button.x, event->button.y);
            break;
        default:
            return 1;
    }
    return 1;
}

void App::run() {
    SDL_Event event;

    while (aptMainLoop() && this->isRunning) {
        hidScanInput();
        if (hidKeysHeld() & KEY_START) {
            break;
        }
        
        if(currentController) {
            currentController->onFrame();
        }
        
        topScreen->update();
        bottomScreen->update();
        
        SDL_Rect bottomRect = { 40, 240, 400, 240 };

        SDL_BlitSurface(topScreen->getSurface(), NULL, this->surface, NULL);
        SDL_BlitSurface(bottomScreen->getSurface(), NULL, this->surface, &bottomRect);
        SDL_Flip(this->surface);

        SDL_PollEvent(&event);
    }
    deinit();
}

void App::exit() {
    this->isRunning = false;
}

Screen *App::getTopScreen() {
    return this->topScreen;
}

BottomScreen *App::getBottomScreen() {
    return this->bottomScreen;
}

AssetManager *App::getAssetManager() {
    return assetManager;
}

HttpService *App::getHttpService() {
	return httpService;
}
