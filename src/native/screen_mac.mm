#include "native/screen_mac.h"

#import <Cocoa/Cocoa.h>

#ifdef __APPLE__

namespace screen_tool
{
    namespace native
    {
        namespace screen
        {
            int print_screen_info()
            {
                NSArray<NSScreen *> *screens = [NSScreen screens];

                for (NSUInteger i = 0; i < screens.count; ++i) {
                    NSScreen *screen = screens[i];
                    NSRect frame = screen.frame;

                    printf("Screen %lu:\n", (unsigned long)(i + 1));
                    printf("  Origin: (%.0f, %.0f)\n", frame.origin.x, frame.origin.y);
                    printf("  Size: %.0f x %.0f\n", frame.size.width, frame.size.height);
                }

                return 0;
            }

            /**
             * 获取活动屏幕列表及其相关信息
             *
             * @return 活动屏幕列表
             */
            std::vector<ScreenSimpleInfo> get_screen_list()
            {
                std::vector<ScreenSimpleInfo> screenList;  // 存储屏幕信息的容器
                
                NSArray<NSScreen *> *screens = [NSScreen screens];
                for (NSScreen *screen in screens) {
                    NSRect frame = [screen frame];

                    ScreenSimpleInfo screenSimpleInfo;
                    screenSimpleInfo.name = [[screen localizedName] UTF8String];
                    screenSimpleInfo.id = [[screen deviceDescription][@"NSScreenNumber"] unsignedIntValue];
                    screenSimpleInfo.is_primary = [screen isEqualTo:[NSScreen mainScreen]];
                    screenSimpleInfo.bounds = ScreenBounds();
                    screenSimpleInfo.bounds.x = frame.origin.x;
                    screenSimpleInfo.bounds.y = frame.origin.y;
                    screenSimpleInfo.bounds.width = frame.size.width;
                    screenSimpleInfo.bounds.height = frame.size.height;

                    screenList.push_back(screenSimpleInfo);
                }

                return screenList;
            }

            /**
             * 获取主屏幕的边界信息，并将结果存储在给定的 ScreenBounds 结构体指针中。
             *
             * @param screenBounds 存储主屏幕边界信息的 ScreenBounds 结构体指针。
             *                     该结构体包含 x、y、width 和 height 字段，用于存储边界信息。
             * @return 返回整数值 0 表示成功获取主屏幕边界信息，-1 表示失败。
             */
            int get_primary_screen_bounds(ScreenBounds *screenBounds) {
                NSScreen *mainScreen = [NSScreen mainScreen];
                NSRect frame = [mainScreen frame];

                screenBounds->x = frame.origin.x;       // 设置 x 坐标
                screenBounds->y = frame.origin.y;       // 设置 y 坐标
                screenBounds->width = frame.size.width; // 设置宽度
                screenBounds->height = frame.size.height; // 设置高度

                return 0;
            }
        }
    }
}

#endif