#include "three.h"

Screen::Screen() {
    this->contentView = 0;
    this->surface = SDL_CreateRGBSurface(SDL_SWSURFACE, 400, 240, 32, 0, 0, 0, 0);
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
        this->contentView->onDraw(this->surface);
    // sf2d_end_frame();
}

SDL_Surface *Screen::getSurface() {
    return this->surface;
}
