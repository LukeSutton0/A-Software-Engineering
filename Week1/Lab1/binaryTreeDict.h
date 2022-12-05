#pragma once
#include <iostream>

struct Node
{
	char data;
	Node* nextLeft;
	Node* nextRight;

	Node() //default constructor
	{
		data = 0;
		nextLeft = NULL;
		nextRight = NULL;
	}

	Node(char data) { //constructor
		this->data = data;
		this->nextLeft = NULL;
		this->nextRight = NULL;
	}
};

class BinaryTree
{
  private:
    Node* root;
    int size;

  public:
	BinaryTree();
	void NodeCreate(char data);
	void printPathToNode();
};


