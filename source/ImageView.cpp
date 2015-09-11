#include "three.h"

ImageView::ImageView():View() {
    
}

void ImageView::onMeasure(int x, int y, int width, int height) {
    View::onMeasure(x, y, width, height);
    if(this->height == VIEW_WRAP_CONTENT) {
        measuredHeight = texture->height;
    }
    if(this->width == VIEW_WRAP_CONTENT) {
        measuredWidth = texture->width;
    }
    char buffer[100];
    sprintf(buffer, "measuredWidth: %d, measuredHeight: %d", measuredWidth, measuredHeight);
    svcOutputDebugString(buffer, 20);
}

void ImageView::onDraw(gfxScreen_t screen, gfx3dSide_t side) {
    View::onDraw(screen, side);
    float w = (float) (measuredWidth - paddingLeft - paddingRight);
    float scaleX = w/texture->width;
    
    float h = (float) (measuredHeight - paddingTop - paddingBottom);
    float scaleY = h/texture->height;
    
    sf2d_draw_texture_scale(this->texture, measuredX + paddingLeft, measuredY + paddingTop, scaleX, scaleY);
}

void ImageView::setTexture(sf2d_texture *texture) {
    this->texture = texture;
}