//
//  Slider.cpp
//  three
//
//  Created by Andre Uschmann on 21.09.15.
//  Copyright © 2015 Andre Uschmann. All rights reserved.
//

#include "three.h"


Slider::Slider():ViewGroup() {
    mBar = new View(0, 16, VIEW_FILL_PARENT, 2, 0xFFFFFFFF);
    addChild(mBar);
    mValue = 0;
    setHeight(32);
    mHandle = new View(0, 0, 32, 32, 0xAA0000FF);
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
    if(mHandle->getX() + mHandle->getWidth() >= measuredWidth) {
        mHandle->setX(measuredWidth - mHandle->getWidth());
    }
    calculateValue();
    return false;
}

bool Slider::onTouchUp(View *view, TouchEvent *event) {
    App::getInstance()->getBottomScreen()->removeTouchMoveListener(this);
    App::getInstance()->getBottomScreen()->removeTouchUpListener(this);
    return false;
}

void Slider::calculateValue() {
    float handleX = (float) mHandle->getX();
    float totalWidth = (float) measuredWidth - mHandle->getWidth();
    int newValue = (handleX / totalWidth) * 100.0f;
    if(newValue != mValue) {
        mValue = newValue;
        if(mSliderChangedListener) {
            mSliderChangedListener->onSliderChanged(this, mValue);
        }
    }
}