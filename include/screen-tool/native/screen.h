#ifndef NATIVE_SCREEN_H
#define NATIVE_SCREEN_H

#ifdef __linux__
    #include "screen-tool/native/scrren_x11.h"
#endif

#ifdef __APPLE__
    #include "screen-tool/native/screen_mac.h"
#endif

#endif