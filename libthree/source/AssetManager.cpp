//
//  AssetManager.cpp
//  three
//
//  Created by Andre Uschmann on 11.09.15.
//  Copyright (c) 2015 Andre Uschmann. All rights reserved.
//

#include "three.h"


// sf2d_texture *AssetManager::loadTexture(const char* id, const void *buffer) {
//     textures[id] = sfil_load_PNG_buffer(buffer, SF2D_PLACE_RAM);
//     return textures[id];
// }

// sf2d_texture *AssetManager::loadTexture(const char* id, const char *filename) {
//     textures[id] = sfil_load_PNG_file(filename, SF2D_PLACE_RAM);
//     return textures[id];
// }

// sf2d_texture *AssetManager::getTexture(const char* id) {
//     return textures[id];
// }

// sftd_font *AssetManager::loadFont(const char* id, const void *buffer, u32 size) {
//     fonts[id] = sftd_load_font_mem(buffer, size);
//     return fonts[id];
// }

// sftd_font *AssetManager::loadFont(const char* id, const char *filename) {
//     fonts[id] = sftd_load_font_file(filename);
//     return fonts[id];
// }

// sftd_font *AssetManager::getFont(const char* id) {
//     return fonts[id];
// }

NinePatch *AssetManager::loadNinePatch(const char* id, const void *buffer) {
    // sf2d_texture *texture = sfil_load_PNG_buffer(buffer, SF2D_PLACE_RAM);
    // ninePatches[id] = new NinePatch(texture);
    // return ninePatches[id];
}

NinePatch *AssetManager::getNinePatch(const char *id) {
    return ninePatches[id];
}