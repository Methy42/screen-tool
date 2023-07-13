#include "native/scrren_x11.h"

#ifdef __linux__

namespace screen_tool {
    namespace native {
        namespace screen {
            int print_screen_info()
            {
                Display* display = XOpenDisplay(NULL);
                if (display == NULL) {
                    // 处理无法打开 X display 的错误
                    std::cerr << "处理无法打开 X displa" << std::endl;
                    return 1;
                }

                Window window = DefaultRootWindow(display);
                int monitors = 0;
                XRRMonitorInfo* info = XRRGetMonitors(display, window, True, &monitors);

                for (int i = 0; i < monitors; i++)
                {
                    printf("Scrren %d:\n", info[i].noutput);
                    printf("  Origin: (%d, %d)\n", info[i].x, info[i].y);
                    printf("  Size: %d x %d\n", info[i].width, info[i].height);
                }

                XRRFreeMonitors(info);
                XCloseDisplay(display);

                return 0;
            }

            /**
             * 获取活动屏幕列表及其相关信息
             *
             * @return 活动屏幕列表
            */
            std::vector<ScreenSimpleInfo> get_screen_list() {
                std::vector<ScreenSimpleInfo> screenList;

                Display* display = XOpenDisplay(NULL);
                if (display == NULL) {
                    // 处理无法打开 X display 的错误
                    std::cerr << "处理无法打开 X displa" << std::endl;
                    return screenList;
                }

                Window window = DefaultRootWindow(display);
                int monitors = 0;
                XRRMonitorInfo* info = XRRGetMonitors(display, window, True, &monitors);
                
                for(int i = 0; i < monitors; i++)
                {
                    XID id;
                    RROutput* out = info[i].outputs;

                    memcpy(&id, out, sizeof(RROutput));

                    ScreenSimpleInfo screenSimpleInfo;
                    screenSimpleInfo.id = id;
                    screenSimpleInfo.name = XGetAtomName(display, info[i].name);
                    screenSimpleInfo.is_primary = info[i].primary;
                    screenSimpleInfo.bounds = ScreenBounds();
                    screenSimpleInfo.bounds.x = info[i].x;
                    screenSimpleInfo.bounds.y = info[i].y;
                    screenSimpleInfo.bounds.width = info[i].width;
                    screenSimpleInfo.bounds.height = info[i].height;

                    screenList.push_back(screenSimpleInfo);
                }

                XRRFreeMonitors(info);
                XCloseDisplay(display);

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
                if (screenBounds == nullptr)
                {
                    std::cerr << "screenBounds 指针不可为空";
                    return 1;
                }

                Display* display = XOpenDisplay(NULL);
                if (display == NULL) {
                    // 处理无法打开 X display 的错误
                    std::cerr << "处理无法打开 X displa" << std::endl;
                    return 1;
                }

                Window window = DefaultRootWindow(display);
                
                int monitors = 0;
                XRRMonitorInfo* info = XRRGetMonitors(display, window, True, &monitors);

                for (int i = 0; i < monitors; i++)
                {
                    if (info[i].primary == True)
                    {
                        screenBounds->x = info[i].x;
                        screenBounds->y = info[i].y;
                        screenBounds->width = info[i].width;
                        screenBounds->height = info[i].height;

                        XRRFreeMonitors(info);

                        return 0;
                    }
                }

                XRRFreeMonitors(info);

                std::cerr << "没有找到主屏幕设备" << std::endl;
                return 1;
            }
        }
    }
}

#endif