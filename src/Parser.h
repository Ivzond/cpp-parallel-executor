#ifndef PARSER_H
#define PARSER_H

#include "EventQueue.h"
#include "Device.h"

class Parser
{
public:
   /* Constructor with such parameters as:
    * param queue - smart-pointer to the queue
    * param DeviceA - smart-pointer to the Device A
    * param DeviceB - smart-pointer to the Device B
    */
    Parser(std::shared_ptr<EventQueue> queue,
    std::shared_ptr<Device> DeviceA,
    std::shared_ptr<Device> DeviceB);

   /* Function, which starts reading data from devices in parallel mode
    * param loop_count_A - unsigned, which specifies a number of iterations of Data Reading from Device A
    * param loop_count_B - unsigned, which specifies a number of iterations of Data Reading from Device B
    * param crush_index_A - integer, which shows number of iteration, when Device A will stop working
    * param crush_index_B - integer, which shows number of iteration, when Device B will stop working
    */
    void run(size_t loop_count_A, size_t loop_count_B,
    int crush_index_A = -1, int crush_index_B = -1);

private:
   /* Function reads data from device
    * param device - smart-pointer to the device
    * param sleep_duration - seconds, that specify the duration of the interruption for simulated operation
    * param loop_count - unsigned, which specifies a number of iterations of Data Reading from Device
    * param crush_index - integer, which shows number of iteration, when Device will stop working
    */
    void read(std::shared_ptr<Device> device, std::chrono::seconds sleep_duration,
    size_t loop_count, int crush_index);

private:
    std::shared_ptr<EventQueue> queue;
    std::shared_ptr<Device> DeviceA;
    std::shared_ptr<Device> DeviceB;
};

#endif
