#include "WorkDoneEvent.h"

#include <utility>

WorkDoneEvent::WorkDoneEvent(std::shared_ptr<Device> device)
: DeviceEvent(std::move(device)) {}

std::string WorkDoneEvent::toString() const {
    return "Finished " + device->getName();
}
