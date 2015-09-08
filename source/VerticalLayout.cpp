#include "three.h"

void VerticalLayout::layoutChild(View *child, int position) {
    int offsetY = 0;
    for(int i=0; i<position; i++) {
        offsetY += this->children[i]->getMeasuredHeight();
    }
    child->setY(offsetY);
}