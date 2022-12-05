// Lab1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "singlyLinkedList.h"

int main()
{
    Dictionary myDictionary;
    myDictionary.Insert('1','5');
    myDictionary.Insert('2','3');
    myDictionary.Insert('3','7');
    myDictionary.Insert('4','2');
    myDictionary.Insert('5','1');
    myDictionary.Insert('1', '6');

    myDictionary.lookup();
}

