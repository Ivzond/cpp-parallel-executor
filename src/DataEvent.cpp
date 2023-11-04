#include "DataEvent.h"
#include <iostream>
#include <utility>

DataEvent::DataEvent(std::shared_ptr<Device> device)
: DeviceEvent(std::move(device)) {}

std::string DataEvent::toString() const {
    return device->getDataAsString() + " from " + device->getName();
}