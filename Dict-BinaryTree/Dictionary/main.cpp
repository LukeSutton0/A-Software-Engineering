// Lab1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include "dictionary.h"
int main()
{
    /*
    Dictionary dict;
    dict.insert(22, "Jane");
    dict.insert(22,"Mary");
    dict.insert(0,"Harold"); //issues with nullptr
    dict.insert(9, "Edward");
    dict.insert(37, "Victoria");
    dict.insert(4, "Matilda");
    dict.insert(26, "Oliver");
    dict.insert(42, "Elizabeth");
    dict.insert(19, "Henry");
    dict.insert(4, "Stephen");
    dict.insert(24, "James");
    dict.insert(-1, "Edward");
    dict.insert(31, "Annie");
    dict.insert(23, "Elizabeth");
    dict.insert(1, "William");
    dict.insert(26, "Charles");

    Dictionary* dictPtr;
    */
    Dictionary dict;
    dict.insert(7, "John");
    dict.insert(4, "Anne");
    dict.insert(1, "Anne");
    dict.insert(5, "Anne");
    dict.insert(12, "Anne");
    dict.insert(11, "Anne");
    dict.insert(9, "Anne");
    dict.insert(10, "Anne");
    dict.insert(15, "Anne");
    dict.insert(14, "Anne");
    dict.remove(7);

    dict.remove(3);

    dict.lookup(1);
    dict.displayTree();
    _CrtDumpMemoryLeaks();
    //dictToMoveTo = dict3;
    //dictPtr->displayTree();
    //dictPtr->checkRoot();
    //dict.checkRoot();

    //dict2.remove(5);
    //dict2.displayTree();
   // dict.remove(4);
}
