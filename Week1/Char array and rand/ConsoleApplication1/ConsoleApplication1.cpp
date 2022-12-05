// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <random>
#include <stdlib.h>

int main()
{
    srand(time(NULL));
    int speed = rand() % 10;
    std::string test = (speed > 5) ? "breaking the law" : "within acceptable limits";
    std::cout << "Your speed is " << test;

    char message[] = { 'H','I' };
    std::cout << message; //breaks as length not specified so no null character
}

