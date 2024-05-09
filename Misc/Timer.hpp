#pragma once
#include <chrono>
static auto startTime = std::chrono::system_clock::now();
inline int32_t getTime() {
    return std::chrono::duration_cast<std::chrono::microseconds>(
               std::chrono::system_clock::now() - startTime)
        .count();
}