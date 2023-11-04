#include "DeviceEvent.h"

#include <utility>

DeviceEvent::DeviceEvent(std::shared_ptr<Device> device)
: device(std::move(device)) {}
