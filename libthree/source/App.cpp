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

    this->surface = SDL_SetVideoMode(400, 240 * 2, 32, SDL_HWSURFACE | SDL_DUALSCR | SDL_FITHEIGHT);
    // this->surface = SDL_SetVideoMode(400, 240 * 2, 32, SDL_SWSURFACE | SDL_CONSOLEBOTTOM | SDL_FITHEIGHT);
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
    topScreen->update();
    bottomScreen->update();
    switch(event->type) {
        case SDL_MOUSEBUTTONDOWN:
            TouchEvent touchDownEvent;
            touchDownEvent.screenX = event->button.x - 40;
            touchDownEvent.screenY = event->button.y - 240;
            touchDownEvent.targetX = event->button.x - 40;
            touchDownEvent.targetY = event->button.y - 240;
            this->bottomScreen->onTouchDown(&touchDownEvent);
            break;
        case SDL_MOUSEMOTION:
            TouchMoveEvent touchMoveEvent;
            touchMoveEvent.screenX = event->motion.x - 40;
            touchMoveEvent.screenY = event->motion.y - 240;
            touchMoveEvent.targetX = event->motion.x - 40;
            touchMoveEvent.targetY = event->motion.y - 240;
            touchMoveEvent.deltaX = event->motion.xrel;
            touchMoveEvent.deltaY = event->motion.yrel;
            this->bottomScreen->onTouchMove(&touchMoveEvent);
            break;
        case SDL_MOUSEBUTTONUP:
            TouchEvent touchUpEvent;
            touchUpEvent.screenX = event->button.x - 40;
            touchUpEvent.screenY = event->button.y - 240;
            touchUpEvent.targetX = event->button.x - 40;
            touchUpEvent.targetY = event->button.y - 240;
            this->bottomScreen->onTouchUp(&touchUpEvent);
            break;
        default:
            break;
    }
    topScreen->update();
    bottomScreen->update();
    return 1;
}

void App::run() {
    SDL_Event event;
    
    topScreen->update();
    bottomScreen->update();
    while (aptMainLoop() && this->isRunning) {
        hidScanInput();
        if (hidKeysHeld() & KEY_START) {
            break;
        }
        
        if(currentController) {
            currentController->onFrame();
        }
        
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
