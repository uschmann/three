//
//  AssetManager.h
//  three
//
//  Created by Andre Uschmann on 11.09.15.
//  Copyright (c) 2015 Andre Uschmann. All rights reserved.
//

#ifndef __three__AssetManager__
#define __three__AssetManager__

class AssetManager {
public:
    sf2d_texture *loadTexture(int id, const void *buffer);
    sf2d_texture *getTexture(int id);
    sftd_font *loadFont(int id, const void *buffer, u32 size);
    sftd_font *getFont(int id);
protected:
    std::map<int, sf2d_texture *> textures;
    std::map<int, sftd_font *> fonts;
};

#endif /* defined(__three__AssetManager__) */
