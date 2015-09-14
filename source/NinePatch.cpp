//
//  NinePatch.cpp
//  three
//
//  Created by Andre Uschmann on 14.09.15.
//  Copyright (c) 2015 Andre Uschmann. All rights reserved.
//

#include "three.h"

NinePatch::NinePatch(sf2d_texture *texture) {
    mTexture = texture;
    
    // calc slice top left
    int x = 0;
    int y = 0;
    int width = 0;
    int height = 0;
    while(sf2d_get_pixel(mTexture, width, 0) == 0) {
        width++;
    }
    while(sf2d_get_pixel(mTexture, 0, height) == 0) {
        height++;
    }
    mSliceTopLeft.x = 0;
    mSliceTopLeft.y = 0;
    mSliceTopLeft.width = width;
    mSliceTopLeft.height = height;
    
    // calc slice top right
    x = mSliceTopLeft.width;
    while(sf2d_get_pixel(mTexture, x+1, 0) != 0) {
        x++;
    }
    mSliceTopRight.x = x+1;
    mSliceTopRight.y = 0;
    mSliceTopRight.width = mTexture->width - mSliceTopRight.x;
    mSliceTopRight.height = mSliceTopLeft.height;
    
    // calc slice middle left
    mSliceMiddleLeft.x = 0;
    mSliceMiddleLeft.y = mSliceTopLeft.height;
    mSliceMiddleLeft.width = mSliceTopLeft.width;
    y = mSliceMiddleLeft.y;
    while(sf2d_get_pixel(mTexture, 0, y) != 0) {
        y++;
    }
    mSliceMiddleLeft.height = y - mSliceMiddleLeft.y + 1;
    
    // calc slice middle right
    mSliceMiddleRight.x = mSliceTopRight.x;
    mSliceMiddleRight.width = mSliceTopRight.width;
    mSliceMiddleRight.height = mSliceMiddleLeft.height;
    mSliceMiddleRight.y = mSliceMiddleLeft.y;
    
    // calc slice bottom left
    mSliceBottomLeft.x = 0;
    mSliceBottomLeft.y = mSliceMiddleLeft.y + mSliceMiddleLeft.height - 1;
    mSliceBottomLeft.width = mSliceTopLeft.width;
    mSliceBottomLeft.height = mTexture->height - mSliceBottomLeft.y;
    
    // calc slice bottom right
    mSliceBottomRight.x = mSliceTopRight.x;
    mSliceBottomRight.y = mSliceBottomLeft.y;
    mSliceBottomRight.width = mSliceTopRight.width;
    mSliceBottomRight.height = mSliceBottomLeft.height;
}

// sf2d_draw_texture_part (const sf2d_texture *texture, int x, int y, int tex_x, int tex_y, int tex_w, int tex_h)

void NinePatch::draw(int x, int y, int width, int height, int tint) {
    float scaleX = (width - mSliceTopLeft.width - mSliceTopRight.width);
    float scaleY = height - mSliceTopLeft.height - mSliceBottomLeft.height;
    // left side
    sf2d_draw_texture_part_blend(mTexture, x, y, mSliceTopLeft.x + 1, mSliceTopLeft.y + 1, mSliceTopLeft.width, mSliceTopLeft.height, tint);
    sf2d_draw_texture_part_scale_blend(mTexture, x, mSliceMiddleLeft.y + y, mSliceMiddleLeft.x + 1, mSliceMiddleLeft.y + 1, mSliceMiddleLeft.width, 1, 1, scaleY, tint);
    sf2d_draw_texture_part_blend(mTexture, x, y + scaleY + mSliceTopLeft.height, mSliceBottomLeft.x + 1, mSliceBottomLeft.y, mSliceBottomLeft.width, mSliceBottomLeft.height - 1, tint);
    // middle
     sf2d_draw_texture_part_scale_blend(mTexture, x + mSliceTopLeft.width, y, mSliceTopLeft.width + 1, mSliceTopLeft.y + 1, 1, mSliceTopLeft.height, scaleX, 1, tint);
    sf2d_draw_texture_part_scale_blend(mTexture, x + mSliceMiddleLeft.width, y + mSliceMiddleLeft.y, mSliceMiddleLeft.width +1, mSliceMiddleLeft.y, 1, 1, scaleX, scaleY, tint);
    sf2d_draw_texture_part_scale_blend(mTexture, x + mSliceBottomLeft.width, y + scaleY + mSliceTopLeft.height, mSliceBottomLeft.width +1, mSliceBottomLeft.y, 1, mSliceBottomLeft.height - 1, scaleX, 1, tint);
    // right
    sf2d_draw_texture_part_blend(mTexture, x + scaleX + mSliceTopLeft.width, y, mSliceTopRight.x, mSliceTopRight.y + 1, mSliceTopRight.width - 1, mSliceTopRight.height, tint);
    sf2d_draw_texture_part_scale_blend(mTexture, x + scaleX + mSliceTopLeft.width, y + mSliceTopRight.height, mSliceMiddleRight.x, mSliceMiddleRight.y, mSliceMiddleRight.width - 1, 1, 1, scaleY, tint);
    sf2d_draw_texture_part_blend(mTexture, x + scaleX + mSliceTopLeft.width, y + mSliceTopRight.height + scaleY, mSliceBottomRight.x, mSliceBottomRight.y, mSliceBottomRight.width - 1, mSliceBottomRight.height - 1, tint);
}

