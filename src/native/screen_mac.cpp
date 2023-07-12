#include "native/screen_mac.h"

#ifdef __APPLE__

namespace screen_tool {
    namespace native {
        namespace screen_mac {
            int print_screen_info()
            {
                uint32_t screenCount = 0;
                CGGetActiveDisplayList(0, NULL, &screenCount);

                // 创建存储屏幕 ID 的数组
                CGDirectDisplayID displayIDs[screenCount];

                // 获取每个屏幕的 ID
                CGGetActiveDisplayList(screenCount, displayIDs, &screenCount);

                // 打印每个屏幕的尺寸和位置信息
                for (uint32_t i = 0; i < screenCount; ++i) {
                    CGRect bounds = CGDisplayBounds(displayIDs[i]);
                    printf("Screen %u:\n", i + 1);
                    printf("  Origin: (%.0f, %.0f)\n", bounds.origin.x, bounds.origin.y);
                    printf("  Size: %.0f x %.0f\n", bounds.size.width, bounds.size.height);
                }

                return 0;
            }
        }
    }
}

#endif