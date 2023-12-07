#ifndef TESTING

#include <iostream>
#include "Parser.h"
#include "DeviceA.h"
#include "DeviceB.h"

int main(int argc, char * argv[])
{
    int loop_A = 0, loop_B = 0, crush_A = -1, crush_B = -1;
    std::cout << "Input iterations for device A, device B: ";
    std::cin >> loop_A >> loop_B;
    std::cout << "Input crush indices for device A, device B (-1 by default): ";
    std::cin >> crush_A >> crush_B;

    std::shared_ptr<EventQueue> queue = std::make_shared<EventQueue>();
    std::shared_ptr<Device> A = std::make_shared<DeviceA>();
    std::shared_ptr<Device> B = std::make_shared<DeviceB>();

    Parser parser(queue, A, B);

    parser.run(loop_A, loop_B, crush_A, crush_B);

    return 0;
}

#endif