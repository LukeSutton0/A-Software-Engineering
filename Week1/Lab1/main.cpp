// Lab1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "binaryTreeDict.h"

int main()
{
    BinaryTree tree;
    tree.NodeCreate('5');
    tree.NodeCreate('3');
    tree.NodeCreate('7');
    tree.NodeCreate('2');
    tree.NodeCreate('4');
    tree.NodeCreate('9');
    tree.NodeCreate('8');
  

    tree.printPathToNode();
}

