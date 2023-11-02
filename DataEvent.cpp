#include "DataEvent.h"
#include <iostream>

DataEvent::DataEvent(std::shared_ptr<Device> device)
: DeviceEvent(std::move(device)) {}

std::string DataEvent::toString() const {
    return "Data Event from " +
    device->getName() + ": " +
    device->getDataAsString();
}