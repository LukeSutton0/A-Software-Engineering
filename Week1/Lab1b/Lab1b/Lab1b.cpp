// Lab1b.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
struct Node {
    int data;
    struct Node* next;
};
struct Node* head = NULL;


void insert(int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    new_node->data = new_data;
    new_node->next = head;
    head = new_node;
}
void display() {
    struct Node* ptr;
    ptr = head;
    while (ptr != NULL) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}
int main() {
    insert(2);
    insert(1);
    insert(8);
    insert(3);
    insert(9);
    cout << "The linked list is: ";
    display();
    return 0;
}