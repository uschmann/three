#ifndef THREE_TOUCH_UP_LISTENER
#define THREE_TOUCH_UP_LISTENER

class View;

class TouchUpListener {
public:
    virtual bool onTouchUp(View *view, TouchEvent *event);
};

#endif