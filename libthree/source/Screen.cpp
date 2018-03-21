#include "three.h"

Screen::Screen() {
    this->contentView = 0;
}

void Screen::setContentView(View *view) {
    this->contentView = view;
}

void Screen::update() {
    if(contentView) {
        this->contentView->onMeasure(0, 0, 400, 240);
        drawContentView();
    }
}

void Screen::drawContentView() {
    // sf2d_start_frame(GFX_TOP, GFX_LEFT);
        this->contentView->onDraw(GFX_TOP, GFX_LEFT);
    // sf2d_end_frame();
}
