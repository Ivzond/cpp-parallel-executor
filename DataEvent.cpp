#include "DataEvent.h"

class DataEvent : public DeviceEvent
{
public:
    DataEvent(std::shared_ptr<Device> device)
    : DeviceEvent(device) {}

    std::string toString() const {
        return getDevice()->getName();
    }
};