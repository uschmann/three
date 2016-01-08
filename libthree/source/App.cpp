#include "three.h"

App *App::INSTANCE = 0;

App::App() {
    this->init();
}

void App::init() {
    // init sf2dlib
    sf2d_init();
    sf2d_set_clear_color(RGBA8(0x00, 0x00, 0x00, 0xFF));
    sftd_init();
    
    this->isRunning = true;
    this->topScreen = new Screen();
    this->bottomScreen = new BottomScreen();
    this->assetManager = new AssetManager();
    this->httpService = new HttpService();
}

void App::deinit() {
    sf2d_fini();
}

App *App::getInstance() {
    if(!App::INSTANCE) {
        App::INSTANCE = new App();
    }
    return App::INSTANCE;
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
        sf2d_swapbuffers();
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
