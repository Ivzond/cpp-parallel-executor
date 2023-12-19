#ifndef WORKDONEEVENT_H
#define WORKDONEEVENT_H

#include "DeviceEvent.h"

class WorkDoneEvent : public DeviceEvent
{
public:
    using DeviceEvent::DeviceEvent;
    std::string toString() const override;
};

#endif
