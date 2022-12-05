// DynamicArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "DynamicArray.h"
#include <iostream>


DynamicArray::DynamicArray() { //constructor
	size = 0;
	capacity = 0;
	ptrDynamicArray = nullptr;
	
}

void DynamicArray::pushBack(char dataToAdd) {
	if (ptrDynamicArray == nullptr) {
		capacity = 2;
		ptrDynamicArray = new char[capacity];
		ptrDynamicArray[size++] = dataToAdd; //increment size after adding
	}
	//add to char array
	else if (size != capacity) {
		ptrDynamicArray[size++] = dataToAdd;
	}
	else if (size == capacity) {
		capacity = capacity * capacity;
		char* temp = new char[(capacity)];
		for (int i = size; i >= 0;i--) {
			temp[i] = ptrDynamicArray[i];
		}
		delete[] ptrDynamicArray;
		ptrDynamicArray = NULL;
		ptrDynamicArray = temp; //change pointer to point to new array
		temp = NULL;
		ptrDynamicArray[size++] = dataToAdd;
	}
}

void DynamicArray::displayData() {
	for (int i = 0; i < size;i++){
		std::cout << "Array entry " << i << " Contains '" << ptrDynamicArray[i] << "' \n";
	}
}

void DynamicArray :: displayAll() {
	std::cout << "\n Size = " << size << " Capacity = " << capacity << "\n";
	for (int i = 0;i < size;i++) {
		std::cout << "|" << ptrDynamicArray[i];
	}
	for (int i = 0;i < capacity - size +1;i++) {
		std::cout << "| ";
	}
}

void DynamicArray::popBack() {
	if (size == capacity) {
		std::cout << "\n No capacity left to pop back, all cells used";
		return;
	}
	else {
		capacity = capacity - 1;
		char* temp = new char[(capacity)];
		for (int i = size; i >= 0;i--) {
			temp[i] = ptrDynamicArray[i];
		}
		delete[] ptrDynamicArray;
		ptrDynamicArray = NULL;
		ptrDynamicArray = temp; //change pointer to point to new array
		temp = NULL;
	}
}

char DynamicArray::readOnlyRand(int indexNum) {
	if (indexNum < capacity && indexNum >= 0) {
		return ptrDynamicArray[indexNum];
	}
	else {
		std::cout << "\n Index out of range";
		return 1;
	}
}

void DynamicArray::writeOnlyRand(int indexNum, char charToStore) {
	if (indexNum < capacity && indexNum >= 0) {
		ptrDynamicArray[indexNum] = charToStore;
	}
	else {
		std::cout << "\n Index out of range";
	}
}

DynamicArray::~DynamicArray() {
	delete[] ptrDynamicArray;
}