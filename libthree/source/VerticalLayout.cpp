#include "three.h"

VerticalLayout::VerticalLayout():ViewGroup() {

}

void VerticalLayout::onMeasure(int x, int y, int width, int height) {
    ViewGroup::onMeasure(x, y, width, height);
    if(this->height == VIEW_WRAP_CONTENT) {
        int measuredHeight = 0;
        for(u32 i=0; i<this->children.size(); i++) {
            measuredHeight +=this->children[i]->getMeasuredHeight();
        }
        this->measuredHeight = measuredHeight;
    }
}

void VerticalLayout::layoutChild(View *child, int position) {
    int offsetY = 0;
    for(int i=0; i<position; i++) {
        offsetY += this->children[i]->getMeasuredHeight();
    }
    child->setY(offsetY);
}
