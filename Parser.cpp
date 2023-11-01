#include "Parser.h"
#include "StartedEvent.h"
#include "WorkDoneEvent.h"
#include <thread>

// Strange, but include iostream supposed to be here(watch read-function, first "if")
#include <iostream>

Parser::Parser(std::shared_ptr<EventQueue> queue,
std::shared_ptr<Device> DeviceA,
std::shared_ptr<Device> DeviceB)
: queue(queue), DeviceA(DeviceA), DeviceB(DeviceB) {}

void Parser::read(std::shared_ptr<Device> device,
std::chrono::seconds sleep_duration,
size_t loop_count, int crush_index) {
    for (size_t i = 0; i != loop_count; ++i) {
        // Check if the device should stop working
        if (i == static_cast<size_t>(crush_index)) {
            std::cout << device->getName() << " stopped working at iteration " << i << std::endl;
            queue->push(std::make_shared<WorkDoneEvent>(device));
            return;
        }

        std::this_thread::sleep_for(sleep_duration);
        std::shared_ptr<const Event> event;

        if (device == DeviceA) {
            event = std::make_shared<DataEvent>(DeviceA);
        } else if (device == DeviceB) {
            event = std::make_shared<DataEvent>(DeviceB);
        }

        queue->push(event);
    }
}

void Parser::run(size_t loop_count_A, size_t loop_count_B,
int crush_index_A, int crush_index_B) {
    std::thread threadA(&Parser::read, this, DeviceA, std::chrono::seconds(1), loop_count_A, crush_index_A);
    std::thread threadB(&Parser::read, this, DeviceB, std::chrono::seconds(5), loop_count_B, crush_index_B);

    threadA.join();
    threadB.join();

    queue->push(std::make_shared<StartedEvent>(DeviceA));
    queue->push(std::make_shared<StartedEvent>(DeviceB));
}