#ifndef COMMON_SCREEN_BOUNDS_H
#define COMMON_SCREEN_BOUNDS_H

#include <cstdint>
#include <string>

struct ScreenBounds
{
    int x;
    int y;
    int width;
    int height;
};

struct ScreenSimpleInfo
{
    uint32_t id;
    std::string name;
    bool is_primary;
    ScreenBounds* bounds;
};

#endif /* COMMON_SCREEN_BOUNDS_H */