#ifndef THREE_APP
#define THREE_APP

class Controller;

/**
 * @brief The App object represents the running application. It is implemented as a singleton.
 */
class App {
public:
    static App *getInstance();
    
    void run();
    void exit();
    void startController(Controller *controller);
    Screen *getTopScreen();
    BottomScreen *getBottomScreen();
    AssetManager *getAssetManager();
    HttpService *getHttpService();
    SDL_Surface *getSurface();
    static int FilterEvents(const SDL_Event *event);
    int processEvent(const SDL_Event *event);
protected:
    App();
    
    static App *INSTANCE;
    
    bool isRunning;
    SDL_Surface *surface;
    Screen *topScreen;
    BottomScreen *bottomScreen;
    AssetManager *assetManager;
    HttpService *httpService;
    Controller *currentController;
    
    void init();
    void deinit();
};

#endif
