#include "native/scrren_x11.h"

namespace screen_tool {
    namespace native {
        namespace screen_x11 {
            int print_screen_info()
            {
                Display* display = XOpenDisplay(NULL);

                int eventBase, errorBase;
                if (!XineramaQueryExtension(display, &eventBase, &errorBase))
                {
                    printf("Xinerama extension not available.\n");
                    XCloseDisplay(display);
                    return 1;
                }

                int screenCount;
                XineramaScreenInfo* screenInfo = XineramaQueryScreens(display, &screenCount);

                for (int i = 0; i < screenCount; ++i)
                {
                    XineramaScreenInfo info = screenInfo[i];

                    printf("Scrren %d:\n", i + 1);
                    printf("  Origin: (%d, %d)\n", info.x_org, info.y_org);
                    printf("  Size: %d x %d\n", info.width, info.height);
                }

                XFree(screenInfo);
                XCloseDisplay(display);

                return 0;
            }
        }
    }
}