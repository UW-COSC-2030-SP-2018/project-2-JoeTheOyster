// p2_main.cpp
//Joseph DePoyster
//April 29th, 2018
//COSC 2030

#include "p2_sortSearch.h"
#include "p2_hash.h"
#include <functional>


int main()
{
	int hash = 
	//testing quickSort...
	vector <int> numlist;
	int num;
	cout << "Enter some numbers to be sorted..." << endl;
	cin >> num;
	while (num != -99)
	{
		numlist.push_back(num);
		cin >> num;
	}
	
	numlist = quickSort(numlist);
	
	for (int i = 0; i < numlist.size(); i++)
	{
		cout << numlist[i] << " ";
	}
	cout << endl << "		..::END OF QUICK SORT TESTING::.." << endl << endl;


	//testing binary search...
	cout << "Enter number you wish to be found in the list of numbers previously sorted" << endl;
	cin >> num;
	num = binarySearch(numlist, num, 0, numlist.size()-1);
	if (num == -1)
	{
		cout << "Number not found" << endl;
	}
	else 
	{
		cout << "Number found at position: " << num << endl;
	}
	cout << "		..::END	OF BINARY SORT TESTING::..	" << endl << endl;

	
	//testing merge sort
	numlist.clear();
	cout << "Enter another list of numbers to be sorted..." << endl;
	cin >> num;
	while (num != -99)
	{
		numlist.push_back(num);
		cin >> num;
	}

	mergeSort(numlist, 0, numlist.size()-1);

	for (int i = 0; i < numlist.size(); i++)
	{
		cout << numlist[i] << " ";
	}
	cout << endl << "		..::END OF MERGE SORT TESTING::.." << endl << endl;


	//testing slashHash
	int hash;
	string test;
	cout << "Enter a word less than 80 letters long to be hashed..." << endl;
	cin >> test;
	hash = slashHash(test);
	cout << "The hashed value ended up being: " << hash << endl;
	cout << endl << "		..::END OF MERGE SORT TESTING::.." << endl << endl;
   return 0;
}

