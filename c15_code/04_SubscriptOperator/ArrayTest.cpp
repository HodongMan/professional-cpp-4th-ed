#include "Array.h"
#include <cstddef>
#include <iostream>

using namespace std;

void printArray(const Array<int>& arr)
{
	for (size_t i = 0; i < arr.getSize(); i++) {
		cout << arr[i] << " "; // calls the const operator[] because arr is a const object.
	}
	cout << endl;
}

int main()
{
	Array<int> myArray;
	for (size_t i = 0; i < 10; i++) {
		myArray[i] = 100;	// Calls the non-const operator[] because myArray is a non-const object.
	}
	printArray(myArray);

	//Array<int> myArray;
	//for (size_t i = 0; i < 10; i++) {
	//	myArray.setElementAt(i, 100);
	//}
	//for (size_t i = 0; i < 10; i++) {
	//	cout << myArray.getElementAt(i) << " ";
	//}

	return 0;
}
