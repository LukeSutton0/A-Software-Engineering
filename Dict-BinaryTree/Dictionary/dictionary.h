#pragma once
#include <iostream>
#include <string>


class Dictionary
{
private:
	struct Node;
	Node* root = nullptr;
	int size; //do i need this
	void displayEntriesWorker(Node*, int traversalType);
	void displayTreeWorker(Node* currentNode, int indent);
	Node* lookupWorker(int nodeToFind, Node* currentNode);
	Node* lookupWorker(int nodeToRotateAround, Node*& currentNode, Node*& parentNode);
	void insertWorker(int key, std::string data, Node* &currentNode);
	void removeWorker(int nodeToDelete, Node* &currentNode, Node* &parentNode);
	void removeWorkerNoLeaf(Node* &currentNode, Node* &parentNode);
	void deepDeleteWorker(Node*);
	void deepCopyWorker(Node*, Node*, const Dictionary& dictToCopy);
	void rotateLeft(Node*& applyRotationpoint, Node*& parentNode);//Rotates the binary tree nodes left around the first node given
	void rotateRight(Node*& applyRotationpoint,Node*&parentNode); //Rotates the binary tree nodes right around the first node given
public:
	Dictionary();
	void insert(int key, std::string data); //insert
	//int lookup(int key); //lookup iterating
	std::string* lookup(int nodeToFind); //lookup recursive
	void displayEntries(); //display
	void displayTree(); // display, pre post in order
	void remove(int nodeToDelete); //remove
	~Dictionary();
	Dictionary(const Dictionary& dictToCopy);
	bool isLeaf(Node* n);
	void rotateTesting(int keyOfNodeToTest,std::string rotateDirection);
	

};


