#ifndef NATIVE_SCREEN_MAC_H
#define NATIVE_SCREEN_MAC_H

#ifdef __APPLE__

#include <CoreGraphics/CoreGraphics.h>

namespace screen_tool {
    namespace native {
        namespace screen_mac {
            int print_screen_info();
        }
    }
}

#endif

#endif /* NATIVE_SCREEN_MAC_H */