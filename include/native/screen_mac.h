#ifndef NATIVE_SCREEN_MAC_H
#define NATIVE_SCREEN_MAC_H

#ifdef __APPLE__

#include <vector>
#include <iostream>
#include "common/ScreenExtends.h"

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

#endif /* NATIVE_SCREEN_MAC_H */