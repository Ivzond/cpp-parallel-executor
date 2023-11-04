#include "DeviceA.h"
#include <cstdlib> // For generating random data length

std::string DeviceA::getName() {
    return "A";
}

std::string DeviceA::getDataAsString() {
    // Simulate data reading with random length from 0 to 500 characters
    int length = rand() % 501;
    std::string data;
    for (size_t i = 0; i != length; ++i) {
        data += static_cast<char>('A' + rand() % 26);
    }
    return data;
}