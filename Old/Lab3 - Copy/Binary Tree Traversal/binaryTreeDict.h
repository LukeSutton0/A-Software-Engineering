#pragma once
#include <iostream>
#include <string>

struct Node
{
	int key;
	std::string data;
	Node* nodeLeft;
	Node* nodeRight;

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

class BinaryTree
{
  private:
    Node* root;
    int size;
	void displayEntriesWorker(Node*,int traversalType);

  public:
	BinaryTree();
	void NodeCreate(int key,std::string data); //insert
	void printPathToNode(); //lookup
	void displayEntries(); //display
};


