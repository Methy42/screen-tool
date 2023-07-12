#include <iostream>

#ifdef __APPLE__
#include "native/screen_mac.h"
#endif

#ifdef __linux__
#include "native/scrren_x11.h"
#endif

int main() {
#ifdef __APPLE__
    screen_tool::native::screen_mac::print_screen_info();

    std::vector<ScreenSimpleInfo> screens = screen_tool::native::screen_mac::get_screen_list();  // 获取活动屏幕列表

    for (const auto& screen : screens) {
        std::cout << "Screen Name: " << screen.name << std::endl;  // 打印屏幕名称
        std::cout << "Screen ID: " << screen.id << std::endl;  // 打印屏幕 ID
        std::cout << "Screen Is Primary: " << screen.is_primary << std::endl;  // 打印屏幕是否为主屏幕
        std::cout << "Screen Bounds: x=" << screen.bounds->x << ", y=" << screen.bounds->y
                  << ", width=" << screen.bounds->width << ", height=" << screen.bounds->height << std::endl;  // 打印屏幕边界信息

        std::cout << "---------------------" << std::endl;
    }

    ScreenBounds primary_screen_bounds;
    screen_tool::native::screen_mac::get_primary_screen_bounds(&primary_screen_bounds);  // 获取主屏幕边界信息

    std::cout << "Primary Screen Bounds: x=" << primary_screen_bounds.x << ", y=" << primary_screen_bounds.y
              << ", width=" << primary_screen_bounds.width << ", height=" << primary_screen_bounds.height << std::endl;  // 打印主屏幕边界信息
#endif

#ifdef __linux__
    screen_tool::native::screen_x11::print_screen_info();
#endif
}
