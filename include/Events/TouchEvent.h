#ifndef THREE_TOUCH_EVENT
#define THREE_TOUCH_EVENT

/**
 * Stores information about a touch action on the bottom screen
 */
class TouchEvent {
public:
    /** X-Position relativ to the view element that dispatched the event */
    int targetX;
    /** Y-Position relativ to the view element that dispatched the event */
    int targetY;
    /** X-Position relativ to the screen */
    int screenX;
    /** Y-Position relativ to the screen */
    int screenY;
};

#endif