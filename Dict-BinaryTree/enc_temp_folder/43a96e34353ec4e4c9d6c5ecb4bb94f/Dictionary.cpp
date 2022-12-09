#include "dictionary.h"
#include <list>
#include <vector>
#include <stack>
#include <cassert>



Dictionary::Dictionary()
{
    root = nullptr;
}

struct Dictionary::Node
{
    int key;
    std::string data;
    Node* nodeLeft;
    Node* nodeRight;

    //~Node(); //do i put desctructor here or below?

    Node() //default constructor
    {
        data = "";
        nodeLeft = nullptr;
        nodeRight = nullptr;
    }

    Node(int key, std::string data) { //constructor
        this->key = key;
        this->data = data;
        this->nodeLeft = nullptr;
        this->nodeRight = nullptr;
    }
};
/*
Dictionary::Node::~Node() { //node destructor
    delete nodeLeft;
    delete nodeRight;
}
*/

void Dictionary::insert(int key, std::string data) {
    if (root == NULL) {
        root = new Node(key, data);
        return;
    }
    insertWorker(key, data, root);
}

void Dictionary::insertWorker(int key, std::string data, Node* &currentNode) {
    if (key == currentNode->key) {
        currentNode->data = data;
        return;
    }
    Node* newNode = new Node(key, data);
    if (key < currentNode->key) {
        if (currentNode->nodeLeft != nullptr) {
            insertWorker(key, data, currentNode->nodeLeft);
        }
        else {
            currentNode->nodeLeft = newNode;
        }
    }    
    else{
        if (currentNode->nodeRight != nullptr) {
            insertWorker(key, data, currentNode->nodeRight);
        }
        else {
            currentNode->nodeRight = newNode;
        }
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
    currentNode = lookupWorker(nodeToFind, currentNode); //main lookup function
    if (currentNode == nullptr) {
        return nullptr;
    }
    std::string* ndPtr = &currentNode->data;
    return ndPtr; // what am i supposed to be returning
}
Dictionary::Node* Dictionary::lookupWorker(int nodeToFind, Node* currentNode) { //overloaded lookup
    if (currentNode == nullptr) { //notfound
        return nullptr;
    }
    if (currentNode->key == nodeToFind) { //found
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

Dictionary::Node* Dictionary::lookupWorker(int applyRotationKey, Node*& currentNode, Node*& parentNode) { //return parent aswell
    if (currentNode == nullptr) { //notfound
        return nullptr;
    }
    if (applyRotationKey == currentNode->key) { //found
        return currentNode, parentNode;
    }
    parentNode = currentNode;
    if (applyRotationKey < currentNode->key) {
        currentNode = currentNode->nodeLeft;
        lookupWorker(applyRotationKey, currentNode, parentNode);
    }
    else if (applyRotationKey > currentNode->key) {
        currentNode = currentNode->nodeRight;
        lookupWorker(applyRotationKey, currentNode, parentNode);
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

void Dictionary::displayEntries() {
    Node* temp = root;
    int traversalType = 2; //0 pre(stack), 1 pre order, 2 in order, 3 post order
    displayEntriesWorker(temp, traversalType);
}

void Dictionary::displayEntriesWorker(Node* currentNode, int traversalType) {
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
    Node* parentNode = nullptr;
    if (root == nullptr) {
        return;
    }
    removeWorker(nodeToDelete, currentNode, parentNode);
}

void Dictionary::removeWorker(int nodeToDelete, Node* &currentNode, Node* &parentNode) {
    if (nodeToDelete == currentNode->key) {
        if (currentNode->nodeLeft != NULL && currentNode->nodeRight != NULL) {
            //complicated removal has 2 leaves
            removeWorkerNoLeaf(currentNode, parentNode);
        }
        else if (nodeToDelete == root->key) {
            if (root->nodeLeft != nullptr) {
                root = root->nodeLeft;
            }
            else {
                root = root->nodeRight;
            }
        }
        else if (currentNode->nodeLeft != NULL && parentNode->key > currentNode->key) { //has a left node
            if (currentNode->nodeLeft != nullptr) {
                parentNode->nodeLeft = currentNode->nodeLeft;
           }
            else {
                currentNode->nodeLeft = nullptr;
            }
        }
        else if (currentNode->nodeRight != NULL && parentNode->key > currentNode->key) {//has a right node
            if (currentNode->nodeRight != nullptr) {
                parentNode->nodeRight = currentNode->nodeRight;
            }
            else {
                parentNode->nodeRight = nullptr;
            }
        }
        else if (currentNode->nodeLeft == NULL && parentNode->key < currentNode->key) {//has a left node
            if (currentNode->nodeRight != nullptr) {
                parentNode->nodeRight = currentNode->nodeRight;
            }
            else {
                parentNode->nodeRight = nullptr;
            }
        }
        else if (currentNode->nodeRight == NULL && parentNode->key < currentNode->key) { //has a right node
            if (currentNode->nodeLeft != nullptr) {
                parentNode->nodeLeft = currentNode->nodeLeft;
            }
            else {
                currentNode->nodeLeft = nullptr;
            }
        }
        else if (currentNode->nodeLeft == NULL && currentNode->nodeRight == NULL) {//has no child nodes - remove link
            if (parentNode->key > currentNode->key) {
                parentNode->nodeLeft = nullptr;
            }
            else{
                parentNode->nodeRight = nullptr;
            }
        }
        if (currentNode != nullptr) {
            delete currentNode; //deletes selected node
            currentNode = nullptr;
        }
    }
    else{     //if not found right node to delete yet recursive
        parentNode = currentNode;
        if (nodeToDelete < currentNode->key) {
            currentNode = currentNode->nodeLeft;
        }
        else {
            currentNode = currentNode->nodeRight;
        }
        removeWorker(nodeToDelete, currentNode, parentNode);
    }
}

void Dictionary::removeWorkerNoLeaf(Node* &currentNode, Node* &parentNode) {
    Node* nodeToDelete = currentNode; //the node getting deleted
    Node* previousNode = currentNode; //its parent if not root (if root is same) change this?
    currentNode = currentNode->nodeRight; //current Node gets incremented by 1
    while (currentNode->nodeLeft != NULL) { //find smallest key in right subtree
        previousNode = currentNode;
        currentNode = currentNode->nodeLeft;
    }
    if (nodeToDelete == root) { //if root
        previousNode->nodeLeft = currentNode->nodeRight; 
        currentNode->nodeLeft = root->nodeLeft;
        currentNode->nodeRight = root->nodeRight;
        root = currentNode; //change root pointer to start at current Node
    }
    else { //if not root node
        if (currentNode->nodeRight != NULL) { //
            previousNode->nodeLeft = currentNode->nodeRight;
        }
        if (parentNode->key > nodeToDelete->key) {  //check this and one below right way round
            parentNode->nodeLeft = currentNode;
        }
        else{
            parentNode->nodeRight = currentNode;
        }
        currentNode->nodeLeft = nodeToDelete->nodeLeft;

        if (nodeToDelete->nodeRight != currentNode) {
            currentNode->nodeRight = nodeToDelete->nodeRight;
        }
    }
}


Dictionary::~Dictionary() {
    deepDeleteWorker(root);
    //make sure root memory is clear for next tree
}

void Dictionary::deepDeleteWorker(Node* currentNode) {
    if (currentNode == nullptr) {
        return;
    }
    deepDeleteWorker(currentNode->nodeLeft);
    deepDeleteWorker(currentNode->nodeRight);
    delete currentNode;
    currentNode = nullptr;
}

Dictionary::Dictionary(const Dictionary& dictToCopy) //copy
{
    //this->root = dictToCopy.root; //shallow copy
    this->root = new Node(dictToCopy.root->key, dictToCopy.root->data);
    deepCopyWorker(root, dictToCopy.root, dictToCopy);
}
void Dictionary::deepCopyWorker(Node* constructedNode, Node* currentNode, const Dictionary& dictToCopy) {
    if (currentNode->nodeLeft != nullptr) { //has left node
        constructedNode->nodeLeft = new Node(currentNode->nodeLeft->key, currentNode->nodeLeft->data);
        deepCopyWorker(constructedNode->nodeLeft, currentNode->nodeLeft, dictToCopy);
    }
    if (currentNode->nodeRight != nullptr) { //has right node
        constructedNode->nodeRight = new Node(currentNode->nodeRight->key, currentNode->nodeRight->data);
        deepCopyWorker(constructedNode->nodeRight, currentNode->nodeRight, dictToCopy);
    }
    //no children
}

bool Dictionary::isLeaf(Node* nodeToCheck) {
    return(nodeToCheck == nullptr);
}

void Dictionary::checkRoot() {
    std::cout << "\n Root location = "<< root <<" root key value = "<< root->key << "\n ";

}

void Dictionary::rotateTesting(int applyRotationKey,std::string direction) {
    Node* currentNode = root;
    if (root == nullptr) {
        return;
    }
    Node* parentNode = NULL;
    currentNode,parentNode = lookupWorker(applyRotationKey, currentNode,parentNode); //find node
    assert(!isLeaf(currentNode));
    if (direction == "right") { //right
        rotateRight(currentNode, parentNode);
    }
    else { //left
        rotateLeft(currentNode, parentNode);
    }
    if (currentNode == nullptr) {
        return;
    }
}

void Dictionary::rotateRight(Node*& applyRotationpoint, Node*& parentNode) {
    if (applyRotationpoint->nodeLeft != nullptr) {
        Node* B = applyRotationpoint;
        Node* A = applyRotationpoint->nodeLeft;
        Node* beta = applyRotationpoint->nodeLeft->nodeRight;

        if (applyRotationpoint == root) {
            root = A;
        }
        else {
            if (parentNode->key > applyRotationpoint->key) {
                parentNode->nodeLeft = A;
            }
            else {
                parentNode->nodeRight = A;
            }
        }
        B->nodeLeft = beta;
        A->nodeRight = B;
    }
}
void Dictionary::rotateLeft(Node*& applyRotationpoint, Node*& parentNode) {
    if (applyRotationpoint->nodeRight != nullptr) {
        Node* A = applyRotationpoint;
        Node* B = applyRotationpoint->nodeRight;
        Node* beta = applyRotationpoint->nodeRight->nodeLeft;

        if (applyRotationpoint == root) {
            root = B;
        }
        else {
            if (parentNode->key > applyRotationpoint->key) {
                parentNode->nodeLeft = B;
            }
            else {
                parentNode->nodeRight = B;
            }
        }
        B->nodeLeft = A;
        A->nodeRight = beta;
    }
}

Dictionary& Dictionary::operator=(Dictionary&& dictionaryToMove)noexcept { // move but doesnt overload for some reason
    if (this == &dictionaryToMove) {
        return *this;
    }
    deepDeleteWorker(this->root);
    this->root = dictionaryToMove.root;
    dictionaryToMove.root = nullptr;
    return *this;
}

Dictionary::Dictionary(Dictionary&& dictionaryToMove)noexcept { //move
    deepDeleteWorker(this->root);
    this->root = dictionaryToMove.root;
    dictionaryToMove.root = nullptr;
}

Dictionary& Dictionary::operator=(const Dictionary& sourceDictionary) { //deep copy
    if (this == &sourceDictionary) {
        return *this;
    }
    root = new Node(sourceDictionary.root->key, sourceDictionary.root->data);
    deepCopyWorker(this->root,sourceDictionary.root,sourceDictionary);
    return *this;
}
