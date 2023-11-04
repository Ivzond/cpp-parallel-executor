#ifndef DATAEVENT_H
#define DATAEVENT_H

#include "DeviceEvent.h"

class DataEvent : public DeviceEvent
{
public:
	explicit DataEvent(std::shared_ptr<Device> device);
	std::string toString() const override;
};

#endif