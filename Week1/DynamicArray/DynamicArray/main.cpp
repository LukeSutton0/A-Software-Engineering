
#include "DynamicArray.h"
#include <iostream>

int main()
{
	DynamicArray myArray;
	myArray.pushBack('4');
	myArray.pushBack('a');
	myArray.pushBack('7');
	myArray.pushBack('1');
	myArray.pushBack('H');
	
	myArray.displayAll();
	myArray.popBack();
	myArray.displayAll();

	char charToFind = myArray.readOnlyRand(2);
	std::cout << "\n \n"<< "Character found = "<< charToFind << "\n";
	
	myArray.writeOnlyRand(1, 'F');
	myArray.displayData();

}