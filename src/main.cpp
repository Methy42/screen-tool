#ifdef __APPLE__
#include "native/screen_mac.h"
#endif

#ifdef __linux__
#include "native/scrren_x11.h"
#endif

int main() {
#ifdef __linux
    screen_tool::native::screen_x11::print_screen_info();
#endif
}
