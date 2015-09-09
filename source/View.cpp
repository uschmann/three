#include "three.h"

/**
 * Constructor
 */
View::View() {
    this->x = 0;
    this->y = 0;
    this->width = 0;
    this->height = 0;
    this->measuredX = 0;
    this->measuredY = 0;
    this->measuredWidth = 0;
    this->measuredHeight = 0;
    this->backgroundColor = 0;
    setTouchDownListener(0);
    setTouchUpListener(0);
    setTouchMoveListener(0);
}

View::View(int x, int y, int width, int height, int backgroundColor):View() {
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->backgroundColor = backgroundColor;
}

void View::onMeasure(int x, int y, int width, int height) {
    this->measuredX = this->x + x;
    this->measuredY = this->y + y;
    switch(this->width) {
        case VIEW_FILL_PARENT:
            this->measuredWidth = width;
            break;
        case VIEW_WRAP_CONTENT:
            this->measuredWidth = this->paddingLeft + this->paddingRight;
            break;
        default:
            this->measuredWidth = width;
            break;
    }
    
    switch(this->height) {
        case VIEW_FILL_PARENT:
            this->measuredHeight = height;
            break;
        case VIEW_WRAP_CONTENT:
            this->measuredHeight = this->paddingTop + this->paddingBottom;
            break;
        default:
            this->measuredHeight = this->height;
            break;
    }
}

void View::onLayout(int offsetX, int offsetY) {
    this->measuredX = this->x + offsetX;
    this->measuredY = this->y + offsetY;
}

/**
 * Will be called when the view should draw
 * its content to the screen.
 */
void View::onDraw(gfxScreen_t screen, gfx3dSide_t side) {
    sf2d_draw_rectangle_rotate(this->measuredX, this->measuredY, this->measuredWidth, this->measuredHeight, this->backgroundColor, this->rotation);
    if(this->borderTopWidth > 0 && this->borderTopColor != 0) {
        sf2d_draw_rectangle (this->measuredX , this->measuredY, this->measuredWidth, this->borderTopWidth, this->borderTopColor);
    }
    if(this->borderRightWidth > 0 && this->borderRightColor != 0) {
        sf2d_draw_rectangle (this->measuredX + this->measuredWidth - this->borderRightWidth, this->measuredY, this->borderRightWidth, this->measuredHeight, this->borderRightColor);
    }
    if(this->borderBottomWidth > 0 && this->borderBottomColor != 0) {
        sf2d_draw_rectangle (this->measuredX , this->measuredY + this->measuredHeight - this->borderBottomWidth, this->measuredWidth, this->borderBottomWidth, this->borderBottomColor);
    }
    if(this->borderLeftWidth > 0 && this->borderLeftColor != 0) {
        sf2d_draw_rectangle (this->measuredX , this->measuredY, this->borderLeftWidth, this->measuredHeight, this->borderLeftColor);
    }
}

bool View::isTouched(touchPosition *touch) {
    if(touch->px > this->measuredX && touch->px < this->measuredX + this->measuredWidth &&
       touch->py > this->measuredY && touch->py < this->measuredY + this->measuredHeight) {
        return true;
    }
    return false;
}

void View::setTouchDownListener(TouchDownListener *listener)
{
    this->touchDownListener = listener;
}

bool View::onTouchDown(touchPosition *touch) {
    if(this->isTouched(touch) && this->touchDownListener) {
        TouchEvent event;
        event.screenX = touch->px;
        event.screenY = touch->py;
        event.targetX = touch->px - this->measuredX;
        event.targetY = touch->py - this->measuredY;
        return this->touchDownListener->onTouchDown(this, &event);
    }
    return false;
}

void View::setTouchUpListener(TouchUpListener *listener)
{
    this->touchUpListener = listener;
}

bool View::onTouchUp(touchPosition *touch) {
    if(this->isTouched(touch) && this->touchUpListener) {
        TouchEvent event;
        event.screenX = touch->px;
        event.screenY = touch->py;
        event.targetX = touch->px - this->measuredX;
        event.targetY = touch->py - this->measuredY;
        return this->touchUpListener->onTouchUp(this, &event);
    }
    return false;
}

void View::setTouchMoveListener(TouchMoveListener *listener)
{
    this->touchMoveListener = listener;
}

bool View::onTouchMove(touchPosition *touch, int deltaX, int deltaY) {
    if(this->isTouched(touch) && this->touchMoveListener) {
        TouchMoveEvent event;
        event.screenX = touch->px;
        event.screenY = touch->py;
        event.targetX = touch->px - this->measuredX;
        event.targetY = touch->py - this->measuredY;
        event.deltaX = deltaX;
        event.deltaY = deltaY;
        return this->touchMoveListener->onTouchMove(this, &event);
    }
    return false;
}

/*********
 * Setter
 *********/

/**
 * Sets the x-position of the view.
 */
void View::setX(int x) {
    this->x = x;
}

/**
 * Sets the y-position of the view.
 */
void View::setY(int y) {
    this->y = y;
}

/**
 * Sets the width of the view.
 */
void View::setWidth(int width) {
    this->width = width;
}

/**
 * Sets the height of the view.
 */
void View::setHeight(int height) {
    this->height = height;
}

/**
 * Sets the background color of the view.
 * Argument is in the format 0xRRGGBBAA
 */
void View::setBackgroundColor(int backgroundColor) {
    this->backgroundColor = backgroundColor;
}

void View::setBorderColor(int color) {
    this->borderTopColor = color;
    this->borderRightColor = color;
    this->borderBottomColor = color;
    this->borderLeftColor = color;
}

void View::setBorderColor(int colorTop, int colorRight, int colorBottom, int colorLeft) {
    this->borderTopColor = colorTop;
    this->borderRightColor = colorRight;
    this->borderBottomColor = colorBottom;
    this->borderLeftColor = colorLeft;
}

void View::setBorderWidth(int width) {
    this->borderTopWidth = width;
    this->borderRightWidth = width;
    this->borderBottomWidth = width;
    this->borderLeftWidth = width;
}

void View::setBorderWidth(int widthTop, int widthRight, int widthBottom, int widthLeft) {
    this->borderTopWidth = widthTop;
    this->borderRightWidth = widthRight;
    this->borderBottomWidth = widthBottom;
    this->borderLeftWidth = widthLeft;
}

void View::setPadding(int padding) {
    this->paddingTop = padding;
    this->paddingRight = padding;
    this->paddingBottom = padding;
    this->paddingLeft = padding;

}

void View::setPadding(int paddingTop, int paddingRight, int paddingBottom, int paddingLeft) {
    this->paddingTop = paddingTop;
    this->paddingRight = paddingRight;
    this->paddingBottom = paddingBottom;
    this->paddingLeft = paddingLeft;
}

/*********
 * Getter
 *********/

int View::getX() {
    return this->x;
}

int View::getY() {
    return this->y;
}

int View::getWidth() {
    return this->width;
}

int View::getHeight() {
    return this->height;
}

int View::getBackgroundColor() {
    return this->backgroundColor;
}

int View::getMeasuredWidth() {
    return this->measuredWidth;
}

int View::getMeasuredHeight() {
    return this->measuredHeight;
}

