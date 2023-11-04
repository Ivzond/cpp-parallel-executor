#ifndef DEVICE_H
#define DEVICE_H

#include <string>

class Device
{
public:
    virtual ~Device() = default;
    // Returns device name
    virtual std::string getName() = 0;
    /* Simulates data reading
    Returns data */
    virtual std::string getDataAsString() = 0;
};

#endif