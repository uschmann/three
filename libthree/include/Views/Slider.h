//
//  Slider.h
//  three
//
//  Created by Andre Uschmann on 21.09.15.
//  Copyright © 2015 Andre Uschmann. All rights reserved.
//

#ifndef Slider_h
#define Slider_h

class Slider:public ViewGroup, public TouchDownListener, public TouchUpListener, public TouchMoveListener {
public:
    Slider();
    
    void setSliderChangedListener(SliderChangeListener * sliderChangedListener);
    int getValue();
    void setValue(int value);
    void setColor(int color);
    void setSecondaryColor(int secondaryColor);
    
    virtual bool onTouchDown(View *view, TouchEvent *event);
    virtual bool onTouchUp(View *view, TouchEvent *event);
    virtual bool onTouchMove(View *view, TouchMoveEvent *event);
protected:
    ImageView *mHandle;
    View *mBar;
    View *mBarHighlight;
    int mValue;
    int mColor;
    int mSecondaryColor;
    void calculateValue();
    void calculateHandlePosition();
    SliderChangeListener *mSliderChangedListener;
};

#endif /* Slider_h */
