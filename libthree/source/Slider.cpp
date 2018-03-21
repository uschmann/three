//
//  Slider.cpp
//  three
//
//  Created by Andre Uschmann on 21.09.15.
//  Copyright © 2015 Andre Uschmann. All rights reserved.
//
#include <math.h>

#include "three.h"


Slider::Slider():ViewGroup() {
    mValue = 0;
    mColor = 0x009688FF;
    mSecondaryColor = 0xFFFFFFFF;
    setHeight(28);
    setPadding(8, 0, 8, 0);
    mSliderChangedListener = NULL;
    
    mBar = new View(0, 6, VIEW_FILL_PARENT, 2, mSecondaryColor);
    addChild(mBar);
    
    mBarHighlight = new View(0, 6, 0, 2, mColor);
    addChild(mBarHighlight);
    
    mHandle = new ImageView();
    mHandle->setX(0);
    mHandle->setY(0);
    mHandle->setHeight(VIEW_WRAP_CONTENT);
    mHandle->setWidth(VIEW_WRAP_CONTENT);
    mHandle->setTint(mColor);
    // mHandle->setTexture(App::getInstance()->getAssetManager()->getTexture("defaultSliderHandle"));
    mHandle->setTouchDownListener(this);
    addChild(mHandle);
}

void Slider::setSliderChangedListener(SliderChangeListener *sliderChangedListener) {
    mSliderChangedListener = sliderChangedListener;
}

bool Slider::onTouchDown(View *view, TouchEvent *event) {
    App::getInstance()->getBottomScreen()->addTouchMoveListener(this);
    App::getInstance()->getBottomScreen()->addTouchUpListener(this);
    return false;
}

bool Slider::onTouchMove(View *view, TouchMoveEvent *event) {
    mHandle->setX(mHandle->getX() + event->deltaX);
    if(mHandle->getX() <= 0) {
        mHandle->setX(0);
    }
    if(mHandle->getX() + mHandle->getMeasuredWidth() >= measuredWidth) {
        int correctedX = measuredWidth - mHandle->getMeasuredWidth();
        mHandle->setX(correctedX);
    }
    mBarHighlight->setWidth(mHandle->getX() + 6);
    calculateValue();
    return false;
}

void Slider::setColor(int color) {
    mColor = color;
    mHandle->setTint(mColor);
    mBarHighlight->setBackgroundColor(mColor);
}

void Slider::setSecondaryColor(int secondaryColor) {
    mSecondaryColor = secondaryColor;
    mBar->setBackgroundColor(mSecondaryColor);
}

bool Slider::onTouchUp(View *view, TouchEvent *event) {
    App::getInstance()->getBottomScreen()->removeTouchMoveListener(this);
    App::getInstance()->getBottomScreen()->removeTouchUpListener(this);
    return false;
}

void Slider::setValue(int value) {
    if(value != mValue) {
        if(value < 0) {
            value = 0;
        }
        if(value > 100) {
            value = 100;
        }
        mValue = value;
        calculateHandlePosition();
        if(mSliderChangedListener) {
            mSliderChangedListener->onSliderChanged(this, mValue);
        }
    }
}

void Slider::calculateHandlePosition() {
    float totalWidth = (float)(measuredWidth - mHandle->getMeasuredWidth());
    float value = (float)mValue / (float)100;
    mHandle->setX(round(totalWidth * value));
    mBarHighlight->setWidth(round(totalWidth * value) + 6);
}

void Slider::calculateValue() {
    float handleX = (float) mHandle->getX();
    float totalWidth = (float) measuredWidth - mHandle->getMeasuredWidth();
    int newValue = round((handleX / totalWidth) * 100.0f);
    if(newValue != mValue) {
        mValue = newValue;
        if(mSliderChangedListener) {
            mSliderChangedListener->onSliderChanged(this, mValue);
        }
    }
}