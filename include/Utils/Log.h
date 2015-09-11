//
//  Log.h
//  three
//
//  Created by Andre Uschmann on 11.09.15.
//  Copyright (c) 2015 Andre Uschmann. All rights reserved.
//

#ifndef __three__Log__
#define __three__Log__

class Log {
public:
    static void print(const char *msg);
    static void printf(const char *msg, ...);
};

#endif /* defined(__three__Log__) */
