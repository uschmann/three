//
//  NinePatch.h
//  three
//
//  Created by Andre Uschmann on 14.09.15.
//  Copyright (c) 2015 Andre Uschmann. All rights reserved.
//

#ifndef __three__NinePatch__
#define __three__NinePatch__

struct slice {
    int x;
    int y;
    int width;
    int height;
};

class NinePatch {
public:
    NinePatch(sf2d_texture *texture);
    void draw(int x, int y, int width, int height);
protected:
    sf2d_texture *mTexture;
    slice mSliceTopLeft;
    slice mSliceTopRight;
    slice mSliceMiddleRight;
    slice mSliceMiddleLeft;
    slice mSliceBottomLeft;
    slice mSliceBottomRight;
};

#endif /* defined(__three__NinePatch__) */
