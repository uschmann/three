//
//  AssetManager.cpp
//  three
//
//  Created by Andre Uschmann on 11.09.15.
//  Copyright (c) 2015 Andre Uschmann. All rights reserved.
//

#include "three.h"


sf2d_texture *AssetManager::createTexture(int id, const void *buffer) {
    textures[id] = sfil_load_PNG_buffer(buffer, SF2D_PLACE_RAM);
}

sf2d_texture *AssetManager::getTexture(int id) {
    return textures[id];
}