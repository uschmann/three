#ifndef THREE_CONTROLLER
#define THREE_CONTROLLER

/**
 * @brief Base class for all Controllers
 */
class Controller {
public:
    /**
     * @brief Will be called before the Cotroller is executed. All Components should be initialised here.
     * @param App The app that runs this Controller
     */
    virtual void onCreate(App *app);
    virtual void onFrame();
protected:
    /**
     * @brief Returns the app object.
     */
    App *getApp();
    
    /**
     * @brief Sets the contentView of the top screen.
     */
    void setTopContentView(View *view);
    
    /**
     * @brief Sets the content view of the bottom view.
     */
    void setBottomContentView(View *view);
private:
    App *app;
};

#endif