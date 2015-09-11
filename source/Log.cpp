//
//  Log.cpp
//  three
//
//  Created by Andre Uschmann on 11.09.15.
//  Copyright (c) 2015 Andre Uschmann. All rights reserved.
//

#include "three.h"
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

void Log::print(const char *msg) {
    svcOutputDebugString(msg, strlen(msg));
}

void Log::printf(const char *msg, ...) {
    char buffer[256];
    va_list args;
    va_start(args, msg);
    vsnprintf(buffer, 256, msg, args);
    svcOutputDebugString(buffer, strlen(buffer));
    va_end(args);
}