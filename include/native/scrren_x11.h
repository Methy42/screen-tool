#ifndef NATIVE_SCREEN_X11_H
#define NATIVE_SCREEN_X11_H

#ifdef __linux__

#include <X11/Xlib.h>
#include <X11/extensions/Xinerama.h>
#include <iostream>

#include "common/ScreenBounds.h"

namespace screen_tool {
    namespace native {
        namespace screen_x11 {
            int print_screen_info();
        }
    }
}

#endif

#endif /* NATIVE_SCREEN_X11_H */