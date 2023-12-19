#include "EventQueue.h"

void EventQueue::push(const std::shared_ptr<const Event>& event) {
    std::lock_guard<std::mutex> lock(mutex);
    queue.push(event);
    condition_variable.notify_one();
}

std::shared_ptr<const Event> EventQueue::pop(const std::chrono::seconds& duration) {
    std::unique_lock<std::mutex> lock(mutex);
    while (queue.empty()) {
        if (condition_variable.wait_for(lock, duration) == std::cv_status::timeout) {
            // Return nullptr if the queue is empty after waiting for the specified duration
            return nullptr;
        }
    }
    auto event = queue.front();
    queue.pop();
    return event;
}
