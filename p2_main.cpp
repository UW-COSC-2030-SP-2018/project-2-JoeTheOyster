//p2_main.cpp
//Joseph DePoyster
//April 29th, 2018
//COSC 2030

/*
main cpp file used for unit testing all 5 functions
each function will be tested 5 times with different conditions
three of the five tests will be random produced numbers checked against stl functions of the same nature
the two other test will require manual input from the user. 
*/

#include "p2_sortSearch.h"
#include "p2_hash.h"
#include <algorithm>//std::searh and std::sort

int main()
{
	//testing quickSort...
	vector <int> numlist;
	vector <int> numlist2;//identical vector used to be sorted by vector::sort
	int num;
	for (int h = 0; h < 20; h++)//generating random numbers
	{
		num = rand();
		numlist.push_back(num);
		numlist2.push_back(num);
	}
	cout << "The randomly generated numbers are: " << endl;
	for (int i = 0; i < 20; i++)//printing the random numbers
	{
		cout << numlist[i] << ",";
	}
	numlist = quickSort(numlist);//sorting the random numbers
	cout << endl << "Sorted: " << endl;
	for (int j = 0; j < numlist.size(); j++)
	{
		cout << numlist[j] << " ";
	}

	sort(numlist2.begin(), numlist2.end());
	
	
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


	//testing bloom filter
	bloomFilter bloom;
	string one;
	string two;
	string three;
	bool search;
	cout << "enter three words to add to the bloom filter" << endl;
	cin >> one;
	cin >> two;
	cin >> three;
	bloom.add(one);
	bloom.add(two);
	bloom.add(three);
	cout << "enter a word to check if it is in the filter" << endl;
	cin >> one;
	search = bloom.ask(one);
	if (search == true)
	{
		cout << "could be in there" << endl;
	}
	else if (search == false)
	{
		cout << "not in there" << endl;
	}

   return 0;
}

