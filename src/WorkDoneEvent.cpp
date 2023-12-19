#include "WorkDoneEvent.h"

#include <utility>

std::string WorkDoneEvent::toString() const {
    return "Finished " + device->getName();
}
