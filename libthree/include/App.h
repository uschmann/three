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
protected:
    App();
    
    static App *INSTANCE;
    
    bool isRunning;
    Screen *topScreen;
    BottomScreen *bottomScreen;
    AssetManager *assetManager;
    HttpService *httpService;
    Controller *currentController;
    
    void init();
    void deinit();
};

#endif
