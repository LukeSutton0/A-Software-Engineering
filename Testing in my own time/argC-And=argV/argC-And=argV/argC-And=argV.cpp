// argC-And=argV.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
int main(int argc, char** argv) // use in cmd ->  start argC-And=argV.cpp argvstuffhere
{
    if (argc > 1) { //this is the number of inputs after you call the exe 
        std::cout << argc << "\n"; // arg c = number of inputs
        std::cout << argv[1];

        for (int i = 2; i != argc; ++i) {
            std::cout << " " << argv[i];
        }

    }
    std::cout << "\n";
    return 0;
}
