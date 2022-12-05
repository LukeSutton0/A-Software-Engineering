#include "binaryTreeDict.h"
#include <iostream>
#include <list>
#include <vector>
#include <string>

struct Node* root = NULL;

BinaryTree::BinaryTree()
{
    root = nullptr;
    size = 0;
}

void BinaryTree::NodeCreate(char data) {
    
    Node* newNode = new Node(data);
    if (root == NULL) {
        root = newNode;
        return;
    }
    Node* temp = root;
    while (temp->data != NULL) {
        if (temp->nextLeft == NULL && newNode->data < temp->data) {
            temp->nextLeft = newNode;
            return;
        }
        else if (temp->nextRight == NULL && newNode->data > temp->data) {
            temp->nextRight = newNode;
            return;
        }            
        else if (temp->data != NULL && newNode->data < temp->data) { //left
            temp = temp->nextLeft;     
        }
        else if (temp->data != NULL && newNode->data > temp->data) {
            temp = temp->nextRight;
        }
    }    

} 

void BinaryTree::printPathToNode() {
    Node* temp = root;
    if (root == NULL) {
        std::cout << "Tree is empty";
        return;
    }
    int nodeToFind;
    std::cout << "Enter node to find... ";
    std::cin >> nodeToFind;
    bool endOfTree = false;
    while (temp !=NULL && endOfTree == false) {
        std::cout << "\n";
        if (temp->data == nodeToFind + 48) {
            std::cout << "Node found = " << temp->data;
            endOfTree = true;
        }
        else if (temp->data != NULL && (nodeToFind+48) < temp->data) { //left
            std::cout <<"Current node = "<< temp->data << "\n";
            std::cout << "Traverse left " << "\n";
            if (temp->nextLeft != NULL) {
                temp = temp->nextLeft;
                std::cout << "Next node= " << temp->data << "\n";
            }
            else {
                endOfTree = true;
                std::cout << "Next " << temp->data << "\n";
            }
        }
        else if (temp->data != NULL && (nodeToFind + 48) > temp->data) {
            std::cout << "Current node = " << temp->data << "\n";
            std::cout << "Traverse right " << "\n";
            if (temp->nextRight != NULL) {
                temp = temp->nextRight;
                std::cout << "Next node= " << temp->data << "\n";
            }
            else {
                endOfTree = true;
                std::cout << "Next " << temp->data << "\n";
            }
        }
    }
    
}
