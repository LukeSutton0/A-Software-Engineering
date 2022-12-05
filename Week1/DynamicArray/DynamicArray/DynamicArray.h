#pragma once



class DynamicArray {

	private:
		int size;   //static 2 meanings
		int capacity;
		char* ptrDynamicArray; //points to start of array
		

	public:
		DynamicArray();
		~DynamicArray();
		void displayData();
		void displayAll();
		void pushBack(char);
		void popBack();
		char readOnlyRand(int index);
		void writeOnlyRand(int index, char charToStore);
};