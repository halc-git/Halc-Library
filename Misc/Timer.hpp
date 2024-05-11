#pragma once
#include <chrono>
static auto StartTime = std::chrono::system_clock::now();
inline int32_t get_time() {
    return std::chrono::duration_cast<std::chrono::microseconds>(
               std::chrono::system_clock::now() - StartTime)
        .count();
}
