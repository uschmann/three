#include "three.h"

App *App::INSTANCE = 0;

App::App() {
    this->init();
}

void App::init() {
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    romfsInit();

    this->surface = SDL_SetVideoMode(400, 240 * 2, 32, SDL_SWSURFACE | SDL_DUALSCR | SDL_FITHEIGHT);
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

void App::run() {
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
