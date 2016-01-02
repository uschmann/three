#ifndef THREE_TOUCH_DOWN_LISTENER
#define THREE_TOUCH_DOWN_LISTENER

class View;

class TouchDownListener {
public:
    virtual bool onTouchDown(View *view, TouchEvent *event);
};

#endif