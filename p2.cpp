// p2.cpp
//Joseph DePoyster
//April 29th, 2018
//COSC 2030

//A project that includes some search algos and some hash things.
#include <iostream>
#include <vector>
using namespace std;

	//QuickSort
	//Joseph DePoyster
	//based off psuedo code found @http://rosettacode.org/wiki/Sorting_algorithms/Quicksort
	//return a sorted vector of doubles
	vector<double> quickSort(vector<double>& vec1)
	{
		vector<double> less;
		vector<double> more;
		vector<double> pivotList;
		double pivot;
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

int main()
{
	vector <double> numlist;
	int num;
	cout << "Enter some numbers to be sorted..." << endl;
	cin >> num;
	while (num != -9999)
	{
		numlist.push_back(num);
		cin >> num;
	}
	
    return 0;
}

