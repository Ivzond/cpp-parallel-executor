#include "DeviceB.h"
#include <cstdlib> // For generating random integers

std::string DeviceB::getName() {
    return "Device B";
}
std::string DeviceB::getDataAsString() {
    std::string data = std::to_string(rand() % 199) + " " +
                       std::to_string(rand() % 199) + " " +
                       std::to_string(rand() % 199);
    return data;
}

