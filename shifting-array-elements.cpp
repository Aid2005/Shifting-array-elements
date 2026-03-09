#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void InputArray(int(&array)[10]);
void PrintArray(const int(&array)[10]);

int main()
{
	srand(time(NULL));
	int array[10];

	InputArray(array); // Function for entering random numbers into the array
	cout << "Initial array: " << endl;

	PrintArray(array); // Function for printing the array
	cout << "\n(We follow element 1 until it reaches the end)" << endl;
	cout << "------------------------------------------" << endl;

	int swapValue = 0, temp = 0, rotationNumber = 1;

	for (int i = 0; i < 9; i++) // For loop for 9 combinations
	{
		for (int j = 0; j < 10; j++) // Loop for swapping element positions
		{
			if (j == 0) { // For the first value of the array
				swapValue = array[0];
				array[0] = array[9];
			}
			else { // For the remaining values of the array
				temp = array[j];
				array[j] = swapValue;
				swapValue = temp;
			}
		}

		cout << "Rotation no." << rotationNumber << ": ";
		rotationNumber++;

		PrintArray(array); // Function for printing the array inside the loop
		cout << endl;
	}
}

void InputArray(int(&array)[10]) { // Function for entering random numbers from 1-9 into the array
	for (int& n : array) // Loop for traversing the array
		n = rand() % (9 - 1 + 1) + 1;
}

void PrintArray(const int(&array)[10]) { // Function for printing the array
	for (int n : array) // Loop for traversing the array
		cout << n << " ";
}