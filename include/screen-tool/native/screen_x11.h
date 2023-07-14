#ifndef NATIVE_SCREEN_X11_H
#define NATIVE_SCREEN_X11_H

#ifdef __linux__

#include <X11/Xlib.h>
#include <X11/extensions/Xrandr.h>
#include <iostream>
#include <vector>
#include <cstring>

#include "screen-tool/common/ScreenExtends.h"

namespace screen_tool {
    namespace native {
        namespace screen {
            int print_screen_info();

            std::vector<ScreenSimpleInfo> get_screen_list();

            int get_primary_screen_bounds(ScreenBounds *screenBounds);
        }
    }
}

#endif

#endif /* NATIVE_SCREEN_X11_H */