This C++ parallel executor simulates reading data from 2 devices using additional threads and pushes messages about events to the Event queue.
There is a main thread, which pops these messages from the queue and outputs them to the console.
Cases, when one or both of the devices stops working are also handled, just as cases, when incomplete information is submitted to Parser
