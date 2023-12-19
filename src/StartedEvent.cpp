#include "StartedEvent.h"

#include <utility>

std::string StartedEvent::toString() const {
    return "Started " + device->getName();
}
