#pragma once
#include <iostream>
#include <string>

struct Node
{
	int key;
	std::string data;
	Node* nodeLeft;
	Node* nodeRight;

	~Node();

	Node() //default constructor
	{
		data = "";
		nodeLeft = NULL;
		nodeRight = NULL;
	}

	Node(int key,std::string data) { //constructor
		this->key = key;
		this->data = data;
		this->nodeLeft = NULL;
		this->nodeRight = NULL;
	}
};

class Dictionary
{
  private:
    //Node* root;
	Node* root = nullptr;

    int size;
	void displayEntriesWorker(Node*,int traversalType);
	void displayTreeWorker(Node* currentNode, int indent);
	Node* lookupWorker(int nodeToFind, Node* currentNode);
	void insertWorker(int key, std::string data, Node* currentNode);
	void removeWorker(int nodeToDelete, Node* currentNode, Node* parentNode);
	void removeWorkerNoLeaf(Node* currentNode, Node* parentNode);
	void deepDeleteWorker(Node*);
	
	void deepCopyWorker(Node*,Node*, const Dictionary& dictToCopy);

public:
	//Node* root = nullptr; // for copying

	Dictionary();
	void insert(int key,std::string data); //insert
	//int lookup(int key); //lookup iter
	std::string* lookup(int nodeToFind); //lookup rec
	void displayEntries(); //display
	void displayTree(); // display pre post in order
	void remove(int nodeToDelete); //remove
	~Dictionary();
	Dictionary(const Dictionary& dictToCopy);

};


