#ifndef EVENT_H
#define EVENT_H

#include <string>

class Event
{
public:
    virtual ~Event() = default;
    // Returns string message, related to Event
    virtual std::string toString() const = 0;
};

#endif