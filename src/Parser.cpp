#include "Parser.h"
#include "StartedEvent.h"
#include "WorkDoneEvent.h"
#include "DataEvent.h"
#include <thread>

#include <iostream>
#include <utility>

Parser::Parser(std::shared_ptr<EventQueue> queue,
               std::shared_ptr<Device> DeviceA,
               std::shared_ptr<Device> DeviceB)
               : queue(std::move(queue)),
               DeviceA(std::move(DeviceA)),
               DeviceB(std::move(DeviceB)) {
    if (!this->queue || !this->DeviceA || !this->DeviceB) {
        throw std::runtime_error("Invalid arguments");
    }
}

void Parser::read(std::shared_ptr<Device> device,
                  std::chrono::seconds sleep_duration,
                  int loop_count, int crush_index) {
    for (int i = 0; i != loop_count; ++i) {
        // Check if the device should stop working
        if (i == crush_index) {
            return;
        }

        std::this_thread::sleep_for(sleep_duration);
        std::shared_ptr<const Event> event = std::make_shared<DataEvent>(device);

        queue->push(event);
    }
    queue->push(std::make_shared<WorkDoneEvent>(device));
}

void Parser::run(int loop_count_A, int loop_count_B,
                 int crush_index_A, int crush_index_B) {
    queue->push(std::make_shared<StartedEvent>(DeviceA));
    queue->push(std::make_shared<StartedEvent>(DeviceB));

    std::thread threadA(&Parser::read, this, DeviceA, std::chrono::seconds(1), loop_count_A, crush_index_A);
    std::thread threadB(&Parser::read, this, DeviceB, std::chrono::seconds(5), loop_count_B, crush_index_B);

    threadA.join();
    threadB.join();

    // Print events from the queue
    std::shared_ptr<const Event> event;
    while ((event = queue->pop(std::chrono::seconds(0))) != nullptr) 
        std::cout << event->toString() << std::endl;
}
