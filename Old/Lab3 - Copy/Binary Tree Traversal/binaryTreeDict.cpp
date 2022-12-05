#include "binaryTreeDict.h"
#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <stack>

struct Node* root = NULL;

BinaryTree::BinaryTree()
{
    root = nullptr;
    size = 0;
}

void BinaryTree::NodeCreate(int key,std::string data) {
    Node* newNode = new Node(key,data);
    if (root == NULL) {
        root = newNode;
        return;
    }
    bool duplicateKey = false;
    Node* temp = root; //pointing to root
    while (temp->key != NULL && duplicateKey == false) {
        if (temp->nodeLeft == NULL && newNode->key < temp->key) {
            (*temp).nodeLeft = newNode; // (*variable).thing == variable->thing
            return;
        }
        else if (temp->nodeRight == NULL && newNode->key > temp->key) {
            temp->nodeRight = newNode;
            return;
        }            
        else if (temp->key != NULL && newNode->key < temp->key) { //left
            temp = temp->nodeLeft;     
        }
        else if (temp->key != NULL && newNode->key > temp->key) { //right
            temp = temp->nodeRight;
        }
        else if (temp->key != NULL && newNode->key == temp->key) {
            duplicateKey = true;
            temp->data = newNode->data;
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
    std::cin >> nodeToFind; //probs should do error checking
    bool endOfTree = false;
    while (temp !=NULL && endOfTree == false) {
        if (temp->key == nodeToFind) {
            std::cout << "Node found = " << temp->key;
            endOfTree = true;
        }
        else if (temp->key != NULL && (nodeToFind) < temp->key) { //left
            std::cout <<"Current node = "<< temp->key << "\n";
            std::cout << "Traverse left " << "\n";
            if (temp->nodeLeft != NULL) {
                temp = temp->nodeLeft;
                std::cout << "node node= " << temp->key << "\n";
            }
            else {
                endOfTree = true;
                std::cout << "Next " << temp->key << "\n";
            }
        }
        else if (temp->key != NULL && (nodeToFind) > temp->key) {
            std::cout << "Current node = " << temp->key << "\n";
            std::cout << "Traverse right " << "\n";
            if (temp->nodeRight != NULL) {
                temp = temp->nodeRight;
                std::cout << "Next node= " << temp->key << "\n";
            }
            else {
                endOfTree = true;
                std::cout << "Next " << temp->key << "\n";
            }
        }
    }
}

void BinaryTree :: displayEntries() {
    Node* temp = root;
    int traversalType = 1; //0 pre(stack), 1 pre order, 2 in order, 3 post order
    displayEntriesWorker(temp,traversalType);
}

void BinaryTree::displayEntriesWorker(Node* currentNode,int traversalType) {
    if (currentNode == nullptr) {
        return;
    }
    
    if (traversalType == 0) { //pre-order
        std::stack<Node*> nodeStack;
        nodeStack.push(currentNode);

        while (nodeStack.empty() == false) {
            Node* node = nodeStack.top();
            std::cout << node->data << "\n";
            nodeStack.pop();

            if (node->nodeRight) {
                nodeStack.push(node->nodeRight);
            }
            if (node->nodeLeft) {
                nodeStack.push(node->nodeLeft);
            }
        }
    }
    else if (traversalType == 1) { //pre
        std::cout << currentNode->data << "\n";
        displayEntriesWorker(currentNode->nodeLeft, 1);
        displayEntriesWorker(currentNode->nodeRight, 1);
    }
    else if (traversalType == 2) {
        displayEntriesWorker(currentNode->nodeLeft, 1);
        std::cout << currentNode->data << "\n";
        displayEntriesWorker(currentNode->nodeRight, 1);
    }
    else if (traversalType == 3) {
        displayEntriesWorker(currentNode->nodeLeft, 1);
        displayEntriesWorker(currentNode->nodeRight, 1);
        std::cout << currentNode->data << "\n";
    }
    


}