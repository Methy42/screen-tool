#include "native/scrren_x11.h"

namespace screen_tool {
    namespace native {
        namespace screen_x11 {
            int print_screen_info()
            {
                Display* display = XOpenDisplay(NULL);

                int screenCount = XScreenCount(display);

                for (int i = 0; i < screenCount; ++i)
                {
                    Screen* screen = XScreenOfDisplay(display, i);
                    int screenWidth = XWidthOfScreen(screen);
                    int screenHeight = XHeightOfScreen(screen);
                    int screenX = XDisplayWidth(display, i);
                    int screenY = XDisplayHeight(display, i);

                    printf("Screen %d:\n", i + 1);
                    printf("  Origin: (%d, %d)\n", screenX, screenY);
                    printf("  Size: %d x %d\n", screenWidth, screenHeight);
                }

                XCloseDisplay(display);

                return 0;
            }
        }
    }
}