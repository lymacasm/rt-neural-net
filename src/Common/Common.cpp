#include "Common.hpp"
#include <chrono>
#include <cstdint>

using namespace std;
using namespace chrono;

time_t GetTimestampEpoch()
{
    const auto tp = high_resolution_clock::now();
    return duration_cast<milliseconds>(tp.time_since_epoch()).count();
}