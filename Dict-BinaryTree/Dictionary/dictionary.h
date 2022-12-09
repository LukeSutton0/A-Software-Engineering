#pragma once
#include <iostream>
#include <string>
#include <functional>
#include <vector>

class Dictionary
{
private:
	struct Node;
	Node* root = nullptr;
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
	Dictionary& operator=(Dictionary&&)noexcept; //move
	Dictionary& operator=(const Dictionary& sourceDictionary); //copy
	Dictionary();
	~Dictionary();
	Dictionary(const Dictionary& dictToCopy); //copy
	Dictionary(Dictionary&&)noexcept; //move
	void insert(int key, std::string data); //insert
	std::string* lookup(int keyOfNodeToFind); //lookup recursive
	void displayEntries(); //display
	void displayTree(); // display, pre post in order
	void remove(int nodeToDelete); //remove
	bool isLeaf(Node* n);
	void rotateTesting(int keyOfNodeToTest,std::string rotateDirection);
	void checkRoot();
	void removeIf(std::function<bool(int)>);
	void doFindIf(Dictionary::Node* myNode, std::vector<int>& keys, std::function<bool(int)> f);
};


