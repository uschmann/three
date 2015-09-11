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
    sf2d_texture *createTexture(int id, const void *buffer);
    sf2d_texture *getTexture(int id);
protected:
    std::map<int, sf2d_texture *> textures;
};

#endif /* defined(__three__AssetManager__) */
