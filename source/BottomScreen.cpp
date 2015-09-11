#include "three.h"

BottomScreen::BottomScreen() {
    this->isTouchStarted = false;
}

void BottomScreen::update() {
    if(contentView) {
        this->contentView->onMeasure(0, 0, 320, 240);
        this->dispatchTouchEvents();
        drawContentView();
    }
}

void BottomScreen::drawContentView() {
    sf2d_start_frame(GFX_BOTTOM, GFX_LEFT);
        this->contentView->onDraw(GFX_BOTTOM, GFX_LEFT);
    sf2d_end_frame();
}

void BottomScreen::dispatchTouchEvents() {
    touchPosition touch;
    hidTouchRead(&touch);
    if(this->isTouchStarted == true) {
        if(touch.px > 0 || touch.py > 0) {
            int deltaX = touch.px - this->lastTouchX;
            int deltaY = touch.py - this->lastTouchY;
            if(deltaX > 0 || deltaY > 0) {
                // TouchMove accoured
                TouchMoveEvent event;
                event.screenX = touch.px;
                event.screenY = touch.py;
                event.targetX = touch.px;
                event.targetY = touch.py;
                event.deltaX = deltaX;
                event.deltaY = deltaY;
                for(u32 i=0; i<touchMoveListeners.size(); i++) {
                    touchMoveListeners[i]->onTouchMove(0, &event);
                }
                this->contentView->onTouchMove(&touch, deltaX, deltaY);
            }
            this->lastTouchX = touch.px;
            this->lastTouchY = touch.py;
            return;
        }
        // touch up accoured
        this->isTouchStarted = false;
        touch.px = this->lastTouchX;
        touch.py = this->lastTouchY;
        
        TouchEvent event;
        event.screenX = touch.px;
        event.screenY = touch.py;
        event.targetX = touch.px;
        event.targetY = touch.py;
        for(u32 i=0; i<touchUpListeners.size(); i++) {
            touchUpListeners[i]->onTouchUp(0, &event);
        }
        this->contentView->onTouchUp(&touch);
        return;
    }
    if(hidKeysDown() & KEY_TOUCH) {
        // touch down
        TouchEvent event;
        event.screenX = touch.px;
        event.screenY = touch.py;
        event.targetX = touch.px;
        event.targetY = touch.py;
        for(u32 i=0; i<touchDownListeners.size(); i++) {
            touchDownListeners[i]->onTouchDown(0, &event);
        }
        this->contentView->onTouchDown(&touch);
        this->isTouchStarted = true;
    }
    this->lastTouchX = touch.px;
    this->lastTouchY = touch.py;
}

void BottomScreen::addTouchDownListener(TouchDownListener *listener) {
    touchDownListeners.push_back(listener);
}

void BottomScreen::addTouchMoveListener(TouchMoveListener *listener) {
   touchMoveListeners.push_back(listener);
}

void BottomScreen::addTouchUpListener(TouchUpListener *listener) {
    touchUpListeners.push_back(listener);
}

void BottomScreen::removeTouchDownListener(TouchDownListener *listener) {
    touchDownListeners.erase(std::remove(touchDownListeners.begin(), touchDownListeners.end(), listener), touchDownListeners.end());
}

void BottomScreen::removeTouchMoveListener(TouchMoveListener *listener) {
    touchMoveListeners.erase(std::remove(touchMoveListeners.begin(), touchMoveListeners.end(), listener), touchMoveListeners.end());
}

void BottomScreen::removeTouchUpListener(TouchUpListener *listener) {
    touchUpListeners.erase(std::remove(touchUpListeners.begin(), touchUpListeners.end(), listener), touchUpListeners.end());
}
