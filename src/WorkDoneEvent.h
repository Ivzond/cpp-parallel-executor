#ifndef WORKDONEEVENT_H
#define WORKDONEEVENT_H

#include "DeviceEvent.h"

class WorkDoneEvent : public DeviceEvent
{
public:
    explicit WorkDoneEvent(std::shared_ptr<Device> device);

    std::string toString() const override;
};

#endif