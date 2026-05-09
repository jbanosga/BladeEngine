#pragma once

#include <iostream>
#define BLADE_LOG_ERROR(ErrorMsg)                                       \
do                                                                      \
{                                                                       \
    std::cout << "[ERROR] [" << __FILE__ << ":" << __LINE__ << "] - "   \
                << ErrorMsg << "\n";                                    \
} while(0)
