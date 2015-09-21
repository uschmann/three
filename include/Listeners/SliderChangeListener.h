//
//  SliderChangeListener.h
//  three
//
//  Created by Andre Uschmann on 21.09.15.
//  Copyright © 2015 Andre Uschmann. All rights reserved.
//

#ifndef SliderChangeListener_h
#define SliderChangeListener_h

class Slider;

class SliderChangeListener {
public:
    virtual bool onSliderChanged(Slider *slider, int value);
};

#endif /* SliderChangeListener_h */
