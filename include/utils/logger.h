#pragma once

#include <iostream>
#include <stdexcept>

#define BLADE_ASSERT(check, msg)                                        \
if (!check)                                                             \
{                                                                       \
    std::cerr << "[ERROR] [" << __FILE__ << ":" << __LINE__ << "] - "   \
                << msg << "\n";                                         \
    throw  std::runtime_error(msg);                                     \
}

#define BLADE_LOG(msg)                          \
do                                              \
{                                               \
    std::cout << "[INFO] - " << msg << "\n";    \
} while(0)
