#ifndef DATAEVENT_H
#define DATAEVENT_H

#include "DeviceEvent.h"

class DataEvent : public DeviceEvent
{
public:
	using DeviceEvent::DeviceEvent;
	std::string toString() const override;
};

#endif
