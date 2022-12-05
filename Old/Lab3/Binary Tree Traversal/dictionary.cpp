#include "dictionary.h"
#include <list>
#include <vector>
#include <stack>



Dictionary::Dictionary()
{
    root = nullptr;
    size = 0;
}

void Dictionary::insert(int key,std::string data) {
    Node* rootNode = root;

    if (root == NULL) {
        root = new Node(key, data);
        return;
    }
    insertWorker(key, data, rootNode);
} 

void Dictionary::insertWorker(int key, std::string data, Node* currentNode) {
    if (key == currentNode->key) {
        currentNode->data = data;
        return;
    }
    else if (key < currentNode->key && currentNode->nodeLeft != NULL) {
        currentNode = currentNode->nodeLeft;
        insertWorker(key, data, currentNode);
    }
    else if (key > currentNode->key && currentNode->nodeRight != NULL) {
        currentNode = currentNode->nodeRight;
        insertWorker(key, data, currentNode);
    }
    else if (key < currentNode->key && currentNode->nodeLeft == NULL) {
        currentNode->nodeLeft = new Node(key, data);
    }
    else if (key > currentNode->key && currentNode->nodeRight == NULL) {
        currentNode->nodeRight = new Node(key, data);
    }
}

/*void Dictionary::insert(int key, std::string data) {
    Node* newNode = new Node(key, data);
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
*/

std::string* Dictionary::lookup(int nodeToFind) {
    Node* currentNode = root;
    if (root == nullptr) {
        return nullptr;
    }
    currentNode = lookupWorker(nodeToFind, currentNode); //find node
    if (currentNode == nullptr) {
        return nullptr;
    }
    std::string* ndPtr = &currentNode->data;
    return ndPtr; // what am i supposed to be returning

}
Node* Dictionary::lookupWorker(int nodeToFind, Node* currentNode) {
    if (currentNode == nullptr) { //notfound
        return nullptr;
    }
    if (nodeToFind == currentNode->key) { //found
        return currentNode;
    }
    if (nodeToFind < currentNode->key) {
        currentNode = currentNode->nodeLeft;
        lookupWorker(nodeToFind, currentNode);
    }
    else if (nodeToFind > currentNode->key) {
        currentNode = currentNode->nodeRight;
        lookupWorker(nodeToFind, currentNode);
    }
   
}

/*
std::string*  Dictionary::lookup(int nodeToFind) {
    Node* temp = root;
    if (root == NULL) {
        std::cout << "Tree is empty";
        return &temp->data;
    }
    bool endOfTree = false;
    while (temp != NULL && endOfTree == false) {
        if (temp->key == nodeToFind) {
            std::cout << "Node found = " << temp->key;
            endOfTree = true;
        }
        else if (temp->key != NULL && (nodeToFind) < temp->key) { //left
            std::cout << "Current node = " << temp->key << "\n";
            std::cout << "Traverse left " << "\n";
            if (temp->nodeLeft != NULL) {
                temp = temp->nodeLeft;
                std::cout << "Next node= " << temp->key << "\n";
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
    return &temp->data;
} //iterative binary lookup */

void Dictionary :: displayEntries() {
    Node* temp = root;
    int traversalType = 2; //0 pre(stack), 1 pre order, 2 in order, 3 post order
    displayEntriesWorker(temp,traversalType);
}

void Dictionary::displayEntriesWorker(Node* currentNode,int traversalType) {
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
        std::cout << currentNode->key << " " << currentNode->data << "\n";
        displayEntriesWorker(currentNode->nodeLeft, 1);
        displayEntriesWorker(currentNode->nodeRight, 1);
    }
    else if (traversalType == 2) { //in
        displayEntriesWorker(currentNode->nodeLeft, 2);
        std::cout << currentNode->key << " " << currentNode->data << "\n";
        displayEntriesWorker(currentNode->nodeRight, 2);
    }
    else if (traversalType == 3) { //post
        displayEntriesWorker(currentNode->nodeLeft, 3);
        displayEntriesWorker(currentNode->nodeRight, 3);
        std::cout << currentNode->key << " " << currentNode->data << "\n";
    }
}

void Dictionary::displayTree() {
    Node* currentNode = root;
    if (currentNode == nullptr) {
        return;
    }
    displayTreeWorker(currentNode, 0);
}
void Dictionary::displayTreeWorker(Node* currentNode, int indent) {
    if (currentNode == nullptr) {
        return;
    }
    for (int i = 0;i < indent;i++) {
        std::cout << " ";
    }
    std::cout << currentNode->key << " " << currentNode->data << "\n";
    indent++;
    displayTreeWorker(currentNode->nodeLeft, indent);
    indent--;
    indent++;
    displayTreeWorker(currentNode->nodeRight, indent);
    indent--;
}

void Dictionary::remove(int nodeToDelete) {
    Node* currentNode = root;
    Node* parentNode = NULL;
    if (root == NULL) {
        std::cout << "Tree is empty";
        return;
    }
    removeWorker(nodeToDelete,currentNode,parentNode);
}

void Dictionary::removeWorker(int nodeToDelete,Node* currentNode, Node* parentNode) {
    if (currentNode == NULL || currentNode == nullptr) {
        return;
    }
    if (nodeToDelete == currentNode->key) {
        if (currentNode->nodeLeft != NULL && currentNode->nodeRight != NULL) {
            //complicated removal has 2 leaves
            removeWorkerNoLeaf(currentNode,parentNode);
        }
        else if (nodeToDelete == root->key && root->nodeLeft != NULL) { //check this

            root = root->nodeLeft;  //bad cant free memory?
            delete currentNode;
            currentNode = nullptr;
        }
        else if (nodeToDelete == root->key && root->nodeRight != NULL) {
            root = root->nodeRight;
            delete currentNode;
            currentNode = nullptr;
        }

        else if (currentNode->nodeLeft != NULL && parentNode->key > currentNode->key) { 
            //has a left node
            parentNode->nodeLeft = currentNode->nodeLeft;  
        }
        else if (currentNode->nodeRight != NULL && parentNode->key > currentNode->key) { 
            //has a right node
            parentNode->nodeLeft = currentNode->nodeRight;
        }
        else if (currentNode->nodeLeft == NULL && parentNode->key < currentNode->key) { 
            //has a left node
            parentNode->nodeRight = currentNode->nodeRight;
        }
        else if (currentNode->nodeRight == NULL && parentNode->key < currentNode->key) {
            //has a right node
            parentNode->nodeRight = currentNode->nodeRight;
            
        }
        //has no leaves - remove link
        else if (currentNode->nodeLeft == NULL && currentNode->nodeRight == NULL) {
            if (parentNode->key > currentNode->key) {
                parentNode->nodeLeft = NULL;
            }
            else if (parentNode->key < currentNode->key) {
                parentNode->nodeRight = NULL;
            }
        }
        if (currentNode != nullptr) {
            delete currentNode; //deletes selected node
        }
    }
    //havnt found right node to delete yet
    else if (nodeToDelete < currentNode->key) {
        parentNode = currentNode;
        currentNode = currentNode->nodeLeft;
        removeWorker(nodeToDelete, currentNode,parentNode);
    }
    else if (nodeToDelete > currentNode->key) {
        parentNode = currentNode;
        currentNode = currentNode->nodeRight;
        removeWorker(nodeToDelete, currentNode, parentNode);
    }
}

void Dictionary::removeWorkerNoLeaf(Node* currentNode,Node* parentNode) {
    Node* nodeToDelete = currentNode; //the node getting deleted
    Node* previousNode = currentNode; //its parent if not root (if root is same) change this?
    currentNode = currentNode->nodeRight; //current Node gets incremented by 1
    while (currentNode->nodeLeft != NULL) { //find smallest key in right subtree
        previousNode = currentNode;
        currentNode = currentNode->nodeLeft;
    }
    if (nodeToDelete == root) { //if root
        previousNode->nodeLeft = currentNode->nodeRight; //good
        currentNode->nodeLeft = root->nodeLeft;
        currentNode->nodeRight = root->nodeRight;
        root = currentNode; //not sure if this  is good
    }
    else { //if not root node
        if (currentNode->nodeRight != NULL) { //
            previousNode->nodeLeft= currentNode->nodeRight;
        }
        if (parentNode > nodeToDelete) {  //check this and one below right way round
            parentNode->nodeLeft = currentNode;
        }
        else if (parentNode < nodeToDelete) {
            parentNode->nodeRight = currentNode;
        }
        currentNode->nodeLeft = nodeToDelete->nodeLeft;

        if (nodeToDelete->nodeRight != currentNode) {
            currentNode->nodeRight = nodeToDelete->nodeRight;
        }  
    }  
    nodeToDelete = NULL;
    previousNode = NULL;
    delete nodeToDelete;
}

Node::~Node() { //node destructor
    nodeLeft = NULL;
    nodeRight = NULL;
}

Dictionary::~Dictionary() {
    deepDeleteWorker(root);
    //make sure root memory is clear for next tree
    root = nullptr;
    displayTree();
}
void Dictionary::deepDeleteWorker(Node* currentNode) {
    if (currentNode == nullptr) {
        return;
    }
    deepDeleteWorker(currentNode->nodeLeft);
    deepDeleteWorker(currentNode->nodeRight);
    delete currentNode;
}

Dictionary::Dictionary(const Dictionary& dictToCopy)
{
    //this->root = dictToCopy.root; //shallow copy
    root = new Node(dictToCopy.root->key, dictToCopy.root->data);
    deepCopyWorker(root,dictToCopy.root,dictToCopy);
}
void Dictionary::deepCopyWorker(Node* constructedNode, Node* currentNode, const Dictionary& dictToCopy) {
    if (currentNode->nodeLeft!= nullptr){ //has left node
        constructedNode->nodeLeft = new Node(currentNode->nodeLeft->key, currentNode->nodeLeft->data);
        deepCopyWorker(constructedNode->nodeLeft,currentNode->nodeLeft, dictToCopy);
    }
    if (currentNode->nodeRight!= nullptr) { //has right node
        constructedNode->nodeRight = new Node(currentNode->nodeRight->key, currentNode->nodeRight->data);
        deepCopyWorker(constructedNode->nodeRight,currentNode->nodeRight, dictToCopy);
    }
    //no children
}