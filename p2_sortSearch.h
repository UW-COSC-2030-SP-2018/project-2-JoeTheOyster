#pragma once
//p2_sortSearch.h
//Joseph DePoyster
//COSC 2030
//April 29th

/*
	Contains parts 1 - 3 of project 2. This includes:
		-Quick sort function (~line 24)
		-Binary search function (~line 62)
		-Merge sort function & merge function (~line 80)
*/

#include <iostream>
#include <vector>
using namespace std;


//QuickSort function
//Joseph DePoyster
//March 30th, 2018
//based off psuedo code found @http://rosettacode.org/wiki/Sorting_algorithms/Quicksort
//return a sorted vector of integers
vector<int> quickSort(vector<int> vec1)
{
	vector<int> less;
	vector<int> more;
	vector<int> pivotList;
	int pivot;
	if (vec1.size() <= 1)
	{
		return vec1;
	}
	else
	{
		pivot = vec1[(vec1.size()) / 2];
		for (int i = 0; i < vec1.size(); i++)
		{
			if (vec1[i] < pivot)
			{
				less.push_back(vec1[i]);
			}
			else if (vec1[i] > pivot)
			{
				more.push_back(vec1[i]);
			}
			else
			{
				pivotList.push_back(vec1[i]);
			}
		}
		less = quickSort(less);
		more = quickSort(more);
	}
	less.insert(less.end(), pivotList.begin(), pivotList.end());
	less.insert(less.end(), more.begin(), more.end());

	return less;
}


//Binary search function
//Joseph DePoyster
//April 29th 2018
//returns position of a value in a vector if that value exists in the vector
//returns -1 if value does not exist in vector
int binarySearch(vector<int> input, int key, int left, int right)
{
	if (right >= left)
	{
		int middle = (left + right) / 2;
		if (input[middle] == key) return middle;
		if (input[middle] > key) return binarySearch(input, key, left, middle-1);
		return binarySearch(input, key, middle+1, right);
	}
	return -1;
}


//Merge function (used for merge sort)
//Code based off of code found at https://www.geeksforgeeks.org/merge-sort/
//modified by Joseph DePoyster
//April 30th, 2018
//merges two vectors together
//**NOTE** "left" and "right" refer to "smaller" and "bigger" in terms of value.
void merge(vector<int> &input, int left, int middle, int right)
{
	int i, j, k;
	int n1 = middle - left + 1; //size of the left vector 
	int n2 = right - middle; //size of the right vector
	//temporary vectors
	vector<int> L; //left vector
	vector<int> R; //right vector

	//fill L with the left side of the input vector
	for (i = 0; i < n1; i++)
		L.push_back(input[left + i]);
	//fill R with the right side of the input vector
	for (j = 0; j < n2; j++)
		R.push_back(input[middle + 1 + j]);

	//Merge the temp arrays back into arr[l..r]
	i = 0; // Initial index of first subarray
	j = 0; // Initial index of second subarray
	k = left; // Initial index of merged subarray
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			input[k] = L[i];
			i++;
		}
		else
		{
			input[k] = R[j];
			j++;
		}
		k++;
	}
	//Copy the rest of the elements of L
	while (i < n1)
	{
		input[k] = L[i];
		i++;
		k++;
	}
	//copy the rest of the element of R
	while (j < n2)
	{
		input[k] = R[j];
		j++;
		k++;
	}
}


//Merge sort function
//Code based off of code found at https://www.geeksforgeeks.org/merge-sort/
//modified by Joseph DePoyster
//April 30th, 2018
//returns sorted vector
void mergeSort(vector<int> &input, int left, int right)
{
	if (left < right)
	{
		int middle = (left + right) / 2;

		// Sort first and second halves
		mergeSort(input, left, middle);
		mergeSort(input, middle + 1, right);

		merge(input, left, middle, right);
	}
}