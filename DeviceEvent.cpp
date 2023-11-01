#include "DeviceEvent.h"

class DeviceEvent : public Event {
public:
    DeviceEvent(std::shared_ptr<Device> device)
    : device(device) {}
    std::shared_ptr<Device> getDevice() {
        return device;
    }
protected:
    std::shared_ptr<Device> device;
};