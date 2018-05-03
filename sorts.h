#pragma once
//sorts.h
//Joseph DePoyster
//COSC 2030
//April 29th
//A project that includes some search algos and some hash things.
#include <iostream>
#include <vector>
using namespace std;


//QuickSort function
//Joseph DePoyster
//March 30th, 2018
//based off psuedo code found @http://rosettacode.org/wiki/Sorting_algorithms/Quicksort
//return a sorted vector of integers
vector<int> quickSort(vector<int>& vec1)
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
void merge(vector<int> input, int left, int middle, int right)
{
	int i, j, k;

	vector<int> L;
	vector<int> R;

	for (i = 0; i < L.size(); i++)
		L[i] = input[left + i];
	for (j = 0; j < R.size(); j++)
		R[j] = input[middle + 1 + j];


	i = 0; // Initial index of first subarray
	j = 0; // Initial index of second subarray
	k = left; // Initial index of merged subarray
	while (i < L.size() && j < R.size())
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

	while (i < L.size())
	{
		input[k] = L[i];
		i++;
		k++;
	}

	while (j < R.size())
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
void mergeSort(vector<int> input, int left, int right)
{
	if (left < right)
	{
		int middle = left + (right - left) / 2;

		// Sort first and second halves
		mergeSort(input, left, middle);
		mergeSort(input, middle + 1, right);

		merge(input, left, middle, right);
	}
}