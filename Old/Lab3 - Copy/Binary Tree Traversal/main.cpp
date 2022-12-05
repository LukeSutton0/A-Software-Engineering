// Lab1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "binaryTreeDict.h"
#include <string>
int main()
{
    BinaryTree tree;
    tree.NodeCreate(22, "Jane");
    tree.NodeCreate(22,"Mary");
    //tree.NodeCreate(0,"Harold"); //issues with nullptr
    tree.NodeCreate(9, "Edward");
    tree.NodeCreate(37, "Victoria");
    tree.NodeCreate(4, "Matilda");
    tree.NodeCreate(26, "Oliver");
    tree.NodeCreate(42, "Elizabeth");
    tree.NodeCreate(19, "Henry");
    tree.NodeCreate(4, "Stephen");
    tree.NodeCreate(24, "James");
    tree.NodeCreate(-1, "Edward");
    tree.NodeCreate(31, "Annie");
    tree.NodeCreate(23, "Elizabeth");
    tree.NodeCreate(1, "William");
    tree.NodeCreate(26, "Charles");
    
    //tree.printPathToNode();
    tree.displayEntries();
}

