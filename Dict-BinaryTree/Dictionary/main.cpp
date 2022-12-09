// Lab1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include "dictionary.h"

void insertTestData(Dictionary& Dictionary)
{
    Dictionary.insert(22, "Jane");
    Dictionary.insert(22, "Mary");
    Dictionary.insert(0, "Harold");
    Dictionary.insert(9, "Edward");
    Dictionary.insert(37, "Victoria");
    Dictionary.insert(4, "Matilda");
    Dictionary.insert(26, "Oliver");
    Dictionary.insert(42, "Elizabeth");
    Dictionary.insert(19, "Henry");
    Dictionary.insert(4, "Stephen");
    Dictionary.insert(24, "James");
    Dictionary.insert(-1, "Edward");
    Dictionary.insert(31, "Anne");
    Dictionary.insert(23, "Elizabeth");
    Dictionary.insert(1, "William");
    Dictionary.insert(26, "Charles");
}
int main()
{
    Dictionary dict;
    insertTestData(dict);

    dict.removeIf([](int k) {return true; });

}



