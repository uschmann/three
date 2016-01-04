#include "three.h"

HorizontalLayout::HorizontalLayout():ViewGroup() {

}

void HorizontalLayout::onMeasure(int x, int y, int width, int height) {
    ViewGroup::onMeasure(x, y, width, height);
    if(this->height == VIEW_WRAP_CONTENT) {
        int measuredHeight = 0;
        for(u32 i=0; i<this->children.size(); i++) {
            if(this->children[i]->getMeasuredHeight() > measuredHeight) {
                measuredHeight = this->children[i]->getMeasuredHeight();
            }
        }
        this->measuredHeight = measuredHeight;
    }
}

void HorizontalLayout::layoutChild(View *child, int position) {
    int offsetX = 0;
    for(int i=0; i<position; i++) {
        offsetX += this->children[i]->getMeasuredWidth();
    }
    child->setX(offsetX);
}
