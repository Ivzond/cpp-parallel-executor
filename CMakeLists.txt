cmake_minimum_required(VERSION 3.24)
project(ivzond)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ivzond
        DataEvent.cpp
        DataEvent.h
        Device.h
        DeviceA.cpp
        DeviceA.h
        DeviceB.cpp
        DeviceB.h
        DeviceEvent.cpp
        DeviceEvent.h
        Event.h
        EventQueue.cpp
        EventQueue.h
        main.cpp
        Parser.cpp
        Parser.h
        StartedEvent.cpp
        StartedEvent.h
        WorkDoneEvent.cpp
        WorkDoneEvent.h)
