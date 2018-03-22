#ifndef THREE_BOTTOM_SCREEN
#define THREE_BOTTOM_SCREEN

class BottomScreen:public Screen {
public:
    BottomScreen();
    
    virtual void update();
    void addTouchDownListener(TouchDownListener *listener);
    void addTouchMoveListener(TouchMoveListener *listener);
    void addTouchUpListener(TouchUpListener *listener);
    void removeTouchDownListener(TouchDownListener *listener);
    void removeTouchMoveListener(TouchMoveListener *listener);
    void removeTouchUpListener(TouchUpListener *listener);
    
    void onTouchDown(TouchEvent *event);
    void onTouchUp(TouchEvent *event);
    void onTouchMove(TouchMoveEvent *event);

protected:
    
    int lastTouchX;
    int lastTouchY;
    bool isTouchStarted;
    void drawContentView();
    void dispatchTouchEvents();
    
    std::vector<TouchDownListener*> touchDownListeners;
    std::vector<TouchMoveListener*> touchMoveListeners;
    std::vector<TouchUpListener*> touchUpListeners;
};

#endif