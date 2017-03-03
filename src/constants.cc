#include "constants.hh"

namespace czipperz {
bool unlimited_fps = true;
std::chrono::microseconds frame_length(1000000 / 100);

std::atomic<bool> quit(false);
}
