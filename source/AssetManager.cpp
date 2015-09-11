//
//  AssetManager.cpp
//  three
//
//  Created by Andre Uschmann on 11.09.15.
//  Copyright (c) 2015 Andre Uschmann. All rights reserved.
//

#include "three.h"


sf2d_texture *AssetManager::loadTexture(int id, const void *buffer) {
    textures[id] = sfil_load_PNG_buffer(buffer, SF2D_PLACE_RAM);
    return textures[id];
}

sf2d_texture *AssetManager::getTexture(int id) {
    return textures[id];
}

sftd_font *AssetManager::loadFont(int id, const void *buffer, u32 size) {
    fonts[id] = sftd_load_font_mem(buffer, size);
    return fonts[id];
}

sftd_font *AssetManager::getFont(int id) {
    return fonts[id];
}