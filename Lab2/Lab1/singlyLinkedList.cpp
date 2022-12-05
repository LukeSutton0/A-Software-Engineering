#include "singlyLinkedList.h"
#include <iostream>

struct Node* head = NULL;

Dictionary::Dictionary()
{
    head = nullptr;
    size = 0;
}
void Dictionary::Insert(char key,char data) {
    Node* newNode = new Node(key,data);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    if (temp->key == newNode->key) {
        //std::cout << temp->data << newNode->data << "<--";
        temp->data = newNode->data;
        return;
    }
    while (temp->next != NULL) { //while not at end of list keep traversing
        temp = temp->next;  //temp->next = temp.next
    }
    temp->next = newNode; //inserts node at end of traversal
} 
void Dictionary::lookup() {
    Node* temp = head;
    if (head == NULL) {
        std::cout << "List is empty";
        return;
    }
    while (temp != NULL) {
        std::cout << "|| Key = "<<temp->key << " data = " << temp->data;
        temp = temp->next;
    }
}