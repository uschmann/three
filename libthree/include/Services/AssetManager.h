//
//  AssetManager.h
//  three
//
//  Created by Andre Uschmann on 11.09.15.
//  Copyright (c) 2015 Andre Uschmann. All rights reserved.
//

#ifndef __three__AssetManager__
#define __three__AssetManager__

#include <SDL/SDL_ttf.h>

class AssetManager {
public:
    // sf2d_texture *loadTexture(const char* id, const void *buffer);
    // sf2d_texture *loadTexture(const char* id, const char *filename);
    // sf2d_texture *getTexture(const char* id);
    TTF_Font *loadFont(const char* id, const char *filename, int size);
    TTF_Font *getFont(const char* id);
    NinePatch *loadNinePatch(const char* id, const void *buffer);
    NinePatch *getNinePatch(const char* id);
protected:
    // std::map<const char*, sf2d_texture *> textures;
    std::map<const char*, TTF_Font *> fonts;
    std::map<const char*, NinePatch *> ninePatches;
};

#endif /* defined(__three__AssetManager__) */
