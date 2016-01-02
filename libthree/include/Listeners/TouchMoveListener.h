#ifndef THREE_TOUCH_MOVE_LISTENER
#define THREE_TOUCH_MOVE_LISTENER

class View;

class TouchMoveListener {
public:
    virtual bool onTouchMove(View *view, TouchMoveEvent *event);
};

#endif