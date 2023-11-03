#ifndef DEVICEEVENT_H
#define DEVICEEVENT_H

#include "Event.h"
#include "Device.h"

#include <memory>

class DeviceEvent : public Event
{
public:
    // Constructor to fill info about device
    DeviceEvent(std::shared_ptr<Device> device);
protected:
    std::shared_ptr<Device> device;
};

#endif