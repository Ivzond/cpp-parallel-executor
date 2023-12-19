#include "DataEvent.h"
#include <iostream>
#include <utility>

std::string DataEvent::toString() const {
    return device->getDataAsString() + " from " + device->getName();
}
