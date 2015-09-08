//
//  ScrollView.cpp
//  three
//
//  Created by Andre Uschmann on 07.09.15.
//  Copyright (c) 2015 Andre Uschmann. All rights reserved.
//

#include "three.h"

ScrollView::ScrollView():ViewGroup() {
    View();
    scrollY = 0;
    setTouchMoveListener(this);
}

void ScrollView::addChild(View *child) {
    if(getNumberOfChildren() == 0) {
        children.push_back(child);
    }
}

void ScrollView::layoutChild(View *child, int position) {
    child->setY(scrollY);
}

int ScrollView::getScrollY() {
    return scrollY;
}

bool ScrollView::onTouchDown(View *view, TouchEvent *event) {
    return true;
}

bool ScrollView::onTouchMove(View *view, TouchMoveEvent *e) {
    int childHeight = children[0]->getMeasuredHeight();
    if(measuredHeight > childHeight) {
        return true;
    }
    
    scrollY += e->deltaY;
    if(scrollY < ((-1) * childHeight) + measuredHeight) {
        scrollY = ((-1) * childHeight) + measuredHeight;
    }
    return true;
}

bool ScrollView::onTouchUp(View *view, TouchEvent *event) {
    return true;
}