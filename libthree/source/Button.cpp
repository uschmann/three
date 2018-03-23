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
    setPadding(8, 16, 8, 16);
    setBorderWidth(1, 0, 0, 0);
    setBorderColor(0x666666);
    setBackgroundColor(0x333333);
    setBackgroundColorTouchDown(0x111111);
    setFont(App::getInstance()->getAssetManager()->getFont("defaultFont"));
    mTextColor = 0xFFFFFF;
    mTextColorTouchDown = 0xFFFFFF;
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
        TTF_SizeText(this->mFont, this->mText, &measuredWidth, NULL);
        measuredWidth += paddingLeft + paddingRight;
    }
    if(this->height == VIEW_WRAP_CONTENT) {
        TTF_SizeText(this->mFont, this->mText, NULL, &measuredHeight);
        measuredHeight += paddingTop + paddingBottom;
    }
}

void Button::onDraw(SDL_Surface *surface) {
    int stateColor = this->backgroundColor;
    if(mState == BUTTON_STATE_DOWN) {
        stateColor = mBackgroundColorTouchDown;
    }

    SDL_Rect rect = { 0, 0, surface->w, surface->h };
    SDL_FillRect(surface, &rect, stateColor);

    // if(this->backgroundNinePatch) {
    //     this->backgroundNinePatch->draw(this->measuredX, this->measuredY, this->measuredWidth, this->measuredHeight, this->backgroundImageTint);
    // }
    if(this->borderTopWidth > 0 && this->borderTopColor != 0) {
        rect = { 0, 0, surface->w, this->borderTopWidth };
        SDL_FillRect(surface, &rect, this->borderTopColor);
    }
    if(this->borderRightWidth > 0 && this->borderRightColor != 0) {
        rect = { surface->w - this->borderRightWidth, 0, this->borderRightWidth, surface->h };
        SDL_FillRect(surface, &rect, this->borderTopColor);
    }
    if(this->borderBottomWidth > 0 && this->borderBottomColor != 0) {
        rect = { 0, surface->h - this->borderBottomWidth, surface->w, this->borderBottomWidth };
        SDL_FillRect(surface, &rect, this->borderTopColor);
    }
    if(this->borderLeftWidth > 0 && this->borderLeftColor != 0) {
        rect = { 0, 0, this->borderLeftWidth, surface->h };
        SDL_FillRect(surface, &rect, this->borderTopColor);
    }

    // draw text
    int textWidth = 0;
    int textHeight = 0;
    TTF_SizeText(this->mFont, this->mText, &textWidth, &textHeight);
    int centerX = (surface->w) / 2;
    int centerY = (surface->h) / 2;
    rect = { 
        centerX - textWidth / 2, 
        centerY - textHeight / 2
    };

    SDL_Color foregroundColor = { mTextColor & 0xFF, (mTextColor >> 8) & 0xFF, (mTextColor >> 16) & 0xFF };
    SDL_Surface* textSurface = TTF_RenderText_Blended(mFont, mText, foregroundColor);
    SDL_BlitSurface(textSurface, NULL, surface, &rect);
    SDL_FreeSurface(textSurface);
}

void Button::setBackgroundColorTouchDown(int backgroundColorTouchDown) {
    mBackgroundColorTouchDown = backgroundColorTouchDown;
}

void Button::setText(const char *text) {
    mText = text;
}

void Button::setFont(TTF_Font *font) {
    mFont = font;
}

void Button::setTextColor(Uint32 textColor) {
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
