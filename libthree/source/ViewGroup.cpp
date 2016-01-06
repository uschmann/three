#include "three.h"

/**
 * Constructor
 */
ViewGroup::ViewGroup():View() {
    isOverflowHidden = false;
    Log::print("ViewGroup()");
}

void ViewGroup::onMeasure(int x, int y, int width, int height) {
    View::onMeasure(x, y, width, height);
    // measure children
    for(u32 i=0; i<this->children.size(); i++) {
        this->measureChild(this->children[i], i);
        this->layoutChild(this->children[i], i);
        children[i]->onLayout(this->measuredX + this->paddingLeft, this->measuredY + this->paddingTop);
    }
}

void ViewGroup::onDraw(gfxScreen_t screen, gfx3dSide_t side) {
    if(isOverflowHidden) {
        sf2d_set_scissor_test(GPU_SCISSOR_NORMAL, measuredX, measuredY, measuredWidth, measuredHeight);
    }
    View::onDraw(screen, side);
    for(u32 i=0; i<this->children.size(); i++){
        ((View*)this->children[i])->onDraw(screen, side);
    }
}

void ViewGroup::addChild(View *child) {
    this->children.push_back(child);
}

void ViewGroup::setOverflowHidden(bool hidden) {
    isOverflowHidden = hidden;
}

void ViewGroup::layoutChild(View *child, int position) {
    // Childs will layout them self in this basic ViewGroup.
}

void ViewGroup::measureChild(View *child, int position) {
    child->onMeasure(this->measuredX + this->paddingLeft, this->measuredY + this->paddingTop, this->measuredWidth - this->paddingRight - this->paddingLeft, this->measuredHeight - this->paddingBottom - this->paddingTop);
}

int ViewGroup::getNumberOfChildren() {
    return children.size();
}

bool ViewGroup::onTouchDown(touchPosition *touch) {
    if(this->isTouched(touch)) {
        for(u32 i=0; i<this->children.size(); i++){
            if(this->children[i]->onTouchDown(touch)) {
                return true;
            }
        }
        if(this->touchDownListener) {
            TouchEvent *event = new TouchEvent();
            event->screenX = touch->px;
            event->screenY = touch->py;
            event->targetX = touch->px - this->measuredX;
            event->targetY = touch->py - this->measuredY;
            bool result = this->touchDownListener->onTouchDown(this, event);
            delete event;
            return result;
        }
    }
    return false;
}

bool ViewGroup::onTouchUp(touchPosition *touch) {
    if(this->isTouched(touch)) {
        for(u32 i=0; i<this->children.size(); i++){
            if(this->children[i]->onTouchUp(touch)) {
                return true;
            }
        }
        if(this->touchUpListener) {
            TouchEvent *event = new TouchEvent();
            event->screenX = touch->px;
            event->screenY = touch->py;
            event->targetX = touch->px - this->measuredX;
            event->targetY = touch->py - this->measuredY;
            bool result = this->touchUpListener->onTouchUp(this, event);
            delete event;
            return result;
        }
    }
    return false;
}

bool ViewGroup::onTouchMove(touchPosition *touch, int deltaX, int deltaY) {
    if(this->isTouched(touch)) {
        for(u32 i=0; i<this->children.size(); i++){
            if(this->children[i]->onTouchMove(touch, deltaX, deltaY)) {
                return true;
            }
        }
        if(this->touchMoveListener) {
            TouchMoveEvent *event = new TouchMoveEvent();
            event->screenX = touch->px;
            event->screenY = touch->py;
            event->targetX = touch->px - this->measuredX;
            event->targetY = touch->py - this->measuredY;
            event->deltaX = deltaX,
            event->deltaY = deltaY;
            bool result = this->touchMoveListener->onTouchMove(this, event);
            delete event;
            return result;
        }
    }
    return false;
}
