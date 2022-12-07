// Lab1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include "dictionary.h"
int main()
{
    Dictionary dict;
    Dictionary dict2;
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


    dict2.insert(5, "A");
    dict2.insert(3, "B");
    dict2.insert(2, "C");
    dict2.insert(4, "D");
    //dict2.insert(7, "E");
    //dict2.insert(6, "F");
    //dict2.insert(8, "G");

    Dictionary dict3;
    dict3.insert(100,"A");
    dict3.insert(9,"B");
    dict3.insert(7,"C");
    dict3.insert(6,"D");
    dict3.insert(10,"E");
    dict3.insert(8,"F");
    dict3.insert(110, "G");
    //dict3.rotateTesting(100, "left");
    //dict3.displayTree();

    //dict2.displayTree();
    //Dictionary newDict(dict); //deep copy

    Dictionary* dictPtr;


    dictPtr = new Dictionary(std::move(dict)); //move
    //dictToMoveTo = dict3;
    //dictPtr->displayTree();
    //dictPtr->checkRoot();
    Dictionary dict4;
    dict4 = dict2;
    dict4.displayTree();
    //dict.checkRoot();

    //dict2.remove(5);
    //dict2.displayTree();
   // dict.remove(4);
}
