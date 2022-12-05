#pragma once
#include <iostream>

struct Node
{
	char key;
	char data;
	Node* next;

	Node() //default constructor
	{
		key = 0;
		data = 0;
		next = NULL;
	}

	Node(char key,char data) { //constructor
		this->key = key;
		this->data = data;
		this->next = NULL;
	}
};


class Dictionary
{
	private:
		Node* head = nullptr;
		int size;

	public:
		Dictionary();
		void Insert(char key, char data);
		void lookup();

};




