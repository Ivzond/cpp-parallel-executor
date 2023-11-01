#ifndef DEVICE_H
#define DEVICE_H

#include <string>

class Device 
{
    virtual ~Device() {}
    // Returns device name
    virtual std::string getName() const = 0;
    /* Simulates data reading
    Returns data */
    virtual std::string getDataAsString() const = 0;
};

#endif