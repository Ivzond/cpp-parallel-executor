#ifndef STARTEDEVENT_H
#define STARTEDEVENT_H

#include "DeviceEvent.h"

class StartedEvent : public DeviceEvent
{
public:
    using DeviceEvent::DeviceEvent;
    std::string toString() const override;
};

#endif
