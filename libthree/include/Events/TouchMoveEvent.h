#ifndef THREE_TOUCH_MOVE_EVENT
#define THREE_TOUCH_MOVE_EVENT

/**
 * Stores information about a touch action on the bottom screen
 */
class TouchMoveEvent:public TouchEvent {
public:
    /** The horizontal distance */
    int deltaX;
    /** The vertical distance */
    int deltaY;
};

#endif