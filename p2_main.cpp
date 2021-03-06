//p2_main.cpp
//Joseph DePoyster
//April 29th, 2018
//COSC 2030

//revised May 4th, 2018

/*
main cpp file used for unit testing all 5 functions
each function will be tested 5 times with different conditions
three of the five tests will be random produced numbers checked against stl functions of the same nature
the two other test will require manual input from the user. 
*/

#include "p2_sortSearch.h"
#include "p2_hash.h"
#include <algorithm>//std::searh and std::sort
#include <fstream>//used to read in random words from a txt file


//function used to test quicksort
bool quickTest()
{
	vector<int> a;  vector<int> b;
	bool result = true;
		for (int i = 0; i < 100; i++)//creates two identical vectors of size 100 full of random ints
		{
			int num = rand();
			a.push_back(num);
			b.push_back(num);
		}

		a = quickSort(a);//a is sorted by quickSort from p2_sortSearch.h
		sort(b.begin(), b.end());//b is sorted by std::sort

		for (int j = 0; j < 100; j++)
		{
			if (a[j] != b[j])
			{
				result = false;//if test returns false, the vetors were not in the same order.
			}
		}
		return result;
}


//function used to test mergesort
bool mergeTest()
{
	vector<int> a;  vector<int> b;
	bool result = true;
	for (int i = 0; i < 100; i++)//creates two identical vectors of size 100 full of random ints
	{
		int num = rand();
		a.push_back(num);
		b.push_back(num);
	}

	mergeSort(a, 0, a.size()-1);//a is sorted by mergeSort from p2_sortSearch.h
	sort(b.begin(), b.end());//b is sorted by std::sort

	for (int j = 0; j < 100; j++)
	{
		if (a[j] != b[j])
		{
			result = false;//if test returns false, the vetors were not in the same order.
		}
	}
	return result;
}


//function used to test binary search
bool binaryTest()
{
	vector<int> a;
	bool result = true;
	int randSelector;
	int selectorValue;
	int searchResult;
	for (int i = 0; i < 100; i++)//creates vector of size 100 full of random ints
	{
		int num = rand();
		a.push_back(num);
	}
	sort(a.begin(), a.end());
	randSelector = (rand() % 100);//selects a random number between 0 and 100. 
	selectorValue = a[randSelector]; //gets the value at that random selecton
	searchResult = binarySearch(a, selectorValue, 0, a.size()-1); //looks for the value
	if (searchResult != randSelector) //if the position of the value is not equal to the position used to find the value in the first place...
	{
		result = false;
	}
	return result;
}


//function used to test string-to-int hash function
//(testing for collisions out of 6 hashed words at a time)
bool hashTest(string arr[])
{
	bool result = true;
	string words[5];
	int wordsHashed[5];
	int rando;
	for (int i = 0; i < 5; i++)//filling "words" array with random numbers from the bigger array of random numbers
	{
		rando = (rand() % 310);//returns a random number that is in the string array
		words[i] = arr[rando];
		wordsHashed[i] = slashHash(words[i]);//hashes this word and stores it in it's own array.
	}


	//go though and make sure non of the numbers (hashes) in the words array are the same
	if (wordsHashed[0] == wordsHashed[1] || wordsHashed[0] == wordsHashed[2] || wordsHashed[0] == wordsHashed[3] || wordsHashed[0] == wordsHashed[4] || wordsHashed[0] == wordsHashed[5])
	{
		result = false;
	}
	else if (wordsHashed[1] == wordsHashed[0] || wordsHashed[1] == wordsHashed[2] || wordsHashed[1] == wordsHashed[3] || wordsHashed[1] == wordsHashed[4] || wordsHashed[1] == wordsHashed[5])
	{
		result = false;
	}
	else if (wordsHashed[2] == wordsHashed[0] || wordsHashed[2] == wordsHashed[1] || wordsHashed[2] == wordsHashed[3] || wordsHashed[2] == wordsHashed[4] || wordsHashed[2] == wordsHashed[5])
	{
		result = false;
	}
	else if (wordsHashed[3] == wordsHashed[0] || wordsHashed[3] == wordsHashed[1] || wordsHashed[3] == wordsHashed[2] || wordsHashed[3] == wordsHashed[4] || wordsHashed[3] == wordsHashed[5])
	{
		result = false;
	}
	else if (wordsHashed[4] == wordsHashed[0] || wordsHashed[4] == wordsHashed[1] || wordsHashed[4] == wordsHashed[2] || wordsHashed[4] == wordsHashed[3] || wordsHashed[4] == wordsHashed[5])
	{
		result = false;
	}
	else if (wordsHashed[5] == wordsHashed[0] || wordsHashed[5] == wordsHashed[1] || wordsHashed[5] == wordsHashed[2] || wordsHashed[5] == wordsHashed[3] || wordsHashed[5] == wordsHashed[4])
	{
		result = false;
	}

	return result;
}


//function used to test bloom filter
bool bloomTest(string arr[])
{
	bloomFilter filter;
	bool result = true;
	string words[5];
	int rando;
	for (int i = 0; i < 5; i++)//filling "words" array with random numbers from the bigger array of random numbers
	{
		rando = (rand() % 310);//returns a random number that is in the string array
		words[i] = arr[rando];
		filter.add(words[i]);//adds string to bloom filter
	}
	
	//checking if any of the words are not [possibly] found in the bloom filter. 
	if ((filter.ask(words[0])) != true)
	{
		result = false;
	}
	else if ((filter.ask(words[1])) != true)
	{
		result = false;
	}
	else if ((filter.ask(words[2])) != true)
	{
		result = false;
	}
	else if ((filter.ask(words[3])) != true)
	{
		result = false;
	}
	else if ((filter.ask(words[4])) != true)
	{
		result = false;
	}
	//checks if words that are not in the filter return possible.
	if (filter.ask("this_word_isnt_in_the_filter") == true) 
	{
		result = false;//trips code if this word that isn't in the filter is returned possible.
	}
	else if(filter.ask("these_words_arnt_on_the_rando_list") == true)
	{
		result = false;
	}
	return result;
}

int main()
{
	//creating array of random strings for the bloom filter and hash tests to use
	//Code used from lab 9 @ https://github.com/UW-COSC-2030-SP-2018/lab9-mapsorting-JoeTheOyster/blob/master/main.cpp
	string randoWords[310];
	ifstream inFile;
	string inbuf;
	int index = 0;
	//opening file
	inFile.open("randomWords.txt");
	//reading in strings to the array
	while (!inFile.eof())//iterate through input file
		if (inFile >> inbuf)//reads strings into a temporary variable
		{
			randoWords[index] = inbuf;//stores the temporary variable in the map
			index++;
		}
	inFile.close();

	//_____________________LET THE TESTING BEGIN____________________________
	bool done = false;
	cout << "Enter an integer to test a function:\n1 -quick sort\n2 -merge sort\n3 -binary search\n4 -text to int hash\n5 -bloom filter\n0 -quit" << endl;
	while (!done)
	{
		int condition;
		cout << "Enter an integer to test a function: "<< endl;
		cin >> condition;
		switch (condition)
		{
		case 0:
			done = true;
			break;

		case 1:
			cout << "..::TESTING QUICK SORT::.." << endl;
			cout << "returns 0 if the the two vectors are in defferent order" << endl;
			cout << "Result for test 1: " << quickTest() << endl;
			cout << "Result for test 2: " << quickTest() << endl;
			cout << "Result for test 3: " << quickTest() << endl;
			cout << "Result for test 4: " << quickTest() << endl;				
			cout << "Result for test 5: " << quickTest() << endl;
			break;

		case 2:
			cout << "..::TESTING MERGE SORT::.." << endl;
			cout << "returns 0 if the the two vectors are in defferent order" << endl;
			cout << "Result for test 1: " << mergeTest() << endl;
			cout << "Result for test 2: " << mergeTest() << endl;
			cout << "Result for test 3: " << mergeTest() << endl;
			cout << "Result for test 4: " << mergeTest() << endl;
			cout << "Result for test 5: " << mergeTest() << endl;
			break;
		case 3:
			cout << "..::TESTING BINARY SEARCH::.." << endl;
			cout << "returns 0 if the location of a random number in the vector was not correct" << endl;
			cout << "Result for test 1: " << binaryTest() << endl;
			cout << "Result for test 2: " << binaryTest() << endl;
			cout << "Result for test 3: " << binaryTest() << endl;
			cout << "Result for test 4: " << binaryTest() << endl;
			cout << "Result for test 5: " << binaryTest() << endl;
			break;
		case 4:
			cout << "..::TESTING TEXT-TO-INT HASH::.." << endl;
			cout << "returns 0 if there was a collision between 5 random words each test" << endl;
			cout << "Result for test 1: " << hashTest(randoWords) << endl;
			cout << "Result for test 2: " << hashTest(randoWords) << endl;
			cout << "Result for test 3: " << hashTest(randoWords) << endl;
			cout << "Result for test 4: " << hashTest(randoWords) << endl;
			cout << "Result for test 5: " << hashTest(randoWords) << endl;
		case 5:
			cout << "..::TESTING BLOOM FILTER::.." << endl;
			cout << "returns 0 if either a word in the filter was not found, or a word not in the filter was found" << endl;
			cout << "Result for test 1: " << bloomTest(randoWords) << endl;
			cout << "Result for test 2: " << bloomTest(randoWords) << endl;
			cout << "Result for test 3: " << bloomTest(randoWords) << endl;
			cout << "Result for test 4: " << bloomTest(randoWords) << endl;
			cout << "Result for test 5: " << bloomTest(randoWords) << endl;
			
		}
	}
   return 0;
}

