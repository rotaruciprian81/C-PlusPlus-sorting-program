// C++ sorting.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>

using namespace std;

//in order to use 3 sorting algorithms 3 different functions have been created
//declaring the functions
void selectionSort(int array[], int n);
void insertionSort(int array[], int n);
void bubbleSort(int array[], int n);

//beginning of the main method
int main()
{
	//declaring variable "o" that will be used into the console to give the opportunity to the user to choose which sorting algorithm to be used to sort the numbers
	char o;
	//declaring an array with 3 positions
	int array[3], n = 3;
	//starting of the "for" loop that will ask the user to 3 times for 6 digits numbers
	for (int i = 0; i < n; i++) {
		//the user will be asked 3 times to enter a VIN number
		//he will be asked to enter the 1st, 2nd, or 3rd VIN number accordingly
		cout << "Please enter " << i + 1 << " VIN number:" << endl;
		//will store the entered numbers into array 
		cin >> array[i];
		//if statement that will check if the number is between 1000000 and 99999 which means that will need to have 6 digits
		if (array[i] >= 1000000 || array[i] <= 99999) {
			//if the number will  not have 6 digits, the user will be asked to enter the right length VIN number
			cout << "Please enter a 6 digit number" << endl;
			//the loop will go back to the previous position until the user will enter the right number to be stored (6 digits number)
			i--;
		}

	}
	//end of for loop
	//print on screen the options that the user can chose
	cout << "Please select the sorting algorithm that you want to use:" << endl;
	cout << "1. Selection sort" << endl;
	cout << "2. Insertion sort" << endl;
	cout << "3. Bubble sort" << endl;
	//the number corresponding to the chosen sorting algorithm will be stored into variable "o"
	cin >> o;
	//beginning of the switch statement that will display the results accordingly with the sorting algorithm chosen by the user 
	switch (o) {
		//in case the number 1 will be chosen, this will correspond to the selection sort algorithm
	case '1':
		//calling the function
		selectionSort(array, n);
		//display on screen
		cout << "The sorted VIN numbers, using SELECTION sort algorithm, are:" << endl;
		//will display the sorted numbers from the array one by one
		for (int i = 0; i <= n - 1; i++)
			cout << array[i] << endl;
		//will stop the program after displaying
		break;
		//in case number 2 is chosen, this will correspond to the selection sort algorithm
	case '2':
		//calling the function
		insertionSort(array, n);
		//display on screen
		cout << "The sorted VIN numbers, using INSERTION sort algorithm, are:" << endl;
		//will display the sorted numbers from the array one by one
		for (int i = 0; i <= n - 1; i++)
			cout << array[i] << endl;
		break;
		//will stop the program after displaying
		//in case number 3 is chosen, this will correspond to the bubble sort algorithm
	case '3':
		//calling the function
		bubbleSort(array, n);
		//display on screen
		cout << "The sorted VIN numbers, using BUBBLESORT sort algorithm, are:" << endl;
		//will display the sorted numbers from the array one by one 
		for (int i = 0; i <= n - 1; i++)
			cout << array[i] << endl;
		//will stop the program after displaying
		break;
		//if the chosen character is not 1,2 or 3 it will display an error
	default:
		printf("Error!");
		break;

		_getch();
	}
}

//defining the function that will hold the selection sort algorithm
void selectionSort(int array[], int n)
{	// this sorting algorithm will start from index 0 of the array and will search thru the entire array for the smallest value
	//the smallest value will be swapped with the one from index 0
	//declaring the variables that will be used
	int temp; //temporary variable to hold the value
	int min_pos;//variable that will hold the minimum position
				//begining of the for loop
	for (int i = 0; i < n - 1; i++)
	{	//the minimum position in the array will be considered the current index
		min_pos = i;
		//for each iteration of the outer loop this for loop will find the smallest element in the remaining array
		for (int j = i + 1; j < n; j++)
		{
			//if statement used to check if the current element is smaller than the previously 
			if (array[j] < array[min_pos])
				//the new smallest number will be stored
				min_pos = j;
		}
		//if the min_pos is no longer with i, than a smaller value must have been found, so a swap must occur
		if (min_pos != i)
		{
			temp = array[i];
			array[i] = array[min_pos];
			array[min_pos] = temp;
		}
	}
} // end of the function selectionSort 

  //defining the insertion Sort function that contains the insertion sort algorithm
void insertionSort(int array[], int n) {
	//declaring the variables that will be used
	int i, j, tmp;
	//begining of the for loop that will go thru the array
	for (i = 1; i < n; i++) {
		//the i and j variables are beginning on the same index of the array after every pass of the loop
		j = i;
		//while loop 
		//this will execute only if j is greater than index 0 value and the value of the of the index where j is smaller than the index found left from j 
		while (j > 0 && array[j - 1] > array[j]) {
			//swapping the values 
			tmp = array[j];
			array[j] = array[j - 1];
			array[j - 1] = tmp;
			j--;
		}
	}
}
//end of the insertionSort function
//defining the function bubbleSort
//this algorithm compare each pair of adjacent elements from the beginning of the array
void bubbleSort(int array[], int n) {
	bool swapped = true;
	int x = 0;
	int tmp;
	//if at least one swap has been done the step will repeat
	while (swapped) {
		swapped = false;
		x++;
		//for loop 
		for (int i = 0; i<n - x; i++) {
			if (array[i]>array[i + 1]) {
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				swapped = true;
			}
		}
	}
}


