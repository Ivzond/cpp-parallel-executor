#ifndef TESTING

#include <iostream>
#include "Parser.h"
#include "DeviceA.h"
#include "DeviceB.h"

int main(int argc, char * argv[])
{
    int loop_A = std::stoi(argv[1]);
    int loop_B = std::stoi(argv[2]);
    int crush_A = std::stoi(argv[3]);
    int crush_B = std::stoi(argv[4]);

    auto queue = std::make_shared<EventQueue>();
    auto A = std::make_shared<DeviceA>();
    auto B = std::make_shared<DeviceB>();

    Parser parser(queue, A, B);

    parser.run(loop_A, loop_B, crush_A, crush_B);

    return 0;
}

#endif