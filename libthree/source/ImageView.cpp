#include "three.h"

ImageView::ImageView():View() {
    mTint = 0xFFFFFFFF;
}

void ImageView::onMeasure(int x, int y, int width, int height) {
    View::onMeasure(x, y, width, height);
    if(this->height == VIEW_WRAP_CONTENT) {
        measuredHeight = texture->height;
    }
    if(this->width == VIEW_WRAP_CONTENT) {
        measuredWidth = texture->width;
    }
}

void ImageView::onDraw(gfxScreen_t screen, gfx3dSide_t side) {
    View::onDraw(screen, side);
    float w = (float) (measuredWidth - paddingLeft - paddingRight);
    float scaleX = w/texture->width;
    
    float h = (float) (measuredHeight - paddingTop - paddingBottom);
    float scaleY = h/texture->height;
    
    sf2d_draw_texture_scale_blend(this->texture, measuredX + paddingLeft, measuredY + paddingTop, scaleX, scaleY, mTint);
}

void ImageView::setTexture(sf2d_texture *texture) {
    this->texture = texture;
}

void ImageView::setTint(int tint) {
    mTint = tint;
}