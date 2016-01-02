//
//  ScrollView.h
//  three
//
//  Created by Andre Uschmann on 07.09.15.
//  Copyright (c) 2015 Andre Uschmann. All rights reserved.
//

#ifndef __three__ScrollView__
#define __three__ScrollView__

class ScrollView:public ViewGroup, public TouchDownListener, public TouchUpListener, public TouchMoveListener {
public:
    ScrollView();
    
    virtual void addChild(View *child);
    virtual bool onTouchDown(View *view, TouchEvent *event);
    virtual bool onTouchMove(View *view, TouchMoveEvent *event);
    virtual bool onTouchUp(View *view, TouchEvent *event);
    
    int getScrollY();
protected:
    int scrollY;
    virtual void layoutChild(View *child, int position);
};

#endif /* defined(__three__ScrollView__) */
