#include "StartedEvent.h"

#include <utility>

StartedEvent::StartedEvent(std::shared_ptr<Device> device)
: DeviceEvent(std::move(device)) {}

std::string StartedEvent::toString() const {
    return "Started " + device->getName();
}