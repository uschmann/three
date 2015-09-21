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
    
    virtual bool onTouchDown(View *view, TouchEvent *event);
    virtual bool onTouchUp(View *view, TouchEvent *event);
    virtual bool onTouchMove(View *view, TouchMoveEvent *event);
protected:
    View *mHandle;
    View *mBar;
    int mValue;
    void calculateValue();
    SliderChangeListener *mSliderChangedListener;
};

#endif /* Slider_h */
