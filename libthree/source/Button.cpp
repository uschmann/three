//
//  Button.cpp
//  three
//
//  Created by Andre Uschmann on 21.09.15.
//  Copyright © 2015 Andre Uschmann. All rights reserved.
//

#include "three.h"

Button::Button():View() {
    mText = "";
    setWidth(VIEW_WRAP_CONTENT);
    setHeight(VIEW_WRAP_CONTENT);
    setPadding(16);
    setBorderWidth(1, 0, 0, 0);
    setBorderColor(0xFFFFFF11);
    setBackgroundColor(0x333333FF);
    setBackgroundColorTouchDown(0x222222FF);
    setFont(App::getInstance()->getAssetManager()->getFont("defaultFont"));
    mTextColor = 0xFFFFFFFF;
    mTextColorTouchDown = 0xFFFFFFFF;
    mTextSize = 16;
    setTouchDownListener(this);
    setTouchUpListener(this);
    App::getInstance()->getBottomScreen()->addTouchUpListener(this);
    mClickListener = 0;
    mState = BUTTON_STATE_DEFAULT;
}

Button::~Button() {
    setTouchDownListener(NULL);
    setTouchUpListener(NULL);
    App::getInstance()->getBottomScreen()->removeTouchUpListener(this);
}

void Button::setClickListener(ClickListener *clickListener) {
    mClickListener = clickListener;
}

bool Button::onTouchDown(View *view, TouchEvent *event) {
    mState = BUTTON_STATE_DOWN;
    return false;
}

bool Button::onTouchUp(View *view, TouchEvent *event) {
    if(view == this && mState == BUTTON_STATE_DOWN) {
        mState = BUTTON_STATE_DEFAULT;
        if(mClickListener) {
            mClickListener->onClick(this);
            return true;
        }
    }
    mState = BUTTON_STATE_DEFAULT;
    return false;
}

void Button::onMeasure(int x, int y, int width, int height) {
    View::onMeasure(x, y, width, height);
    if(this->width == VIEW_WRAP_CONTENT) {
        measuredWidth = sftd_get_text_width(mFont, mTextSize, (char *)mText) + paddingLeft + paddingRight;
    }
    if(this->height == VIEW_WRAP_CONTENT) {
        measuredHeight = mTextSize + paddingTop + paddingBottom;
    }
}

void Button::onDraw(gfxScreen_t screen, gfx3dSide_t side) {
    // draw background
    int stateColor = this->backgroundColor;
    if(mState == BUTTON_STATE_DOWN) {
        stateColor = mBackgroundColorTouchDown;
    }
    sf2d_draw_rectangle_rotate(this->measuredX, this->measuredY, this->measuredWidth, this->measuredHeight, stateColor, this->rotation);
    if(this->backgroundNinePatch) {
        this->backgroundNinePatch->draw(this->measuredX, this->measuredY, this->measuredWidth, this->measuredHeight, this->backgroundImageTint);
    }
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
    // draw text
    int textWidth = sftd_get_text_width(mFont, mTextSize, (char *)mText);
    int centerX = (measuredWidth - paddingLeft - paddingRight) / 2;
    int centerY = (measuredHeight - paddingTop -paddingBottom) / 2;
    sftd_draw_text(mFont, this->measuredX + this->paddingLeft + centerX - textWidth / 2, this->measuredY + this->paddingTop + centerY - mTextSize / 2, mTextColor, mTextSize, mText);
}

void Button::setBackgroundColorTouchDown(int backgroundColorTouchDown) {
    mBackgroundColorTouchDown = backgroundColorTouchDown;
}

void Button::setText(const char *text) {
    mText = text;
}

void Button::setFont(sftd_font *font) {
    mFont = font;
}

void Button::setTextColor(int textColor) {
    mTextColor = textColor;
}

void Button::setTextColorTouchDown(int textColorTouchDown) {
    mTextColorTouchDown = textColorTouchDown;
}

void Button::setTextSize(int textSize) {
    mTextSize = textSize;
}

const char *Button::getText() {
    return mText;
}
