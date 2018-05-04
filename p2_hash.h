#pragma once
#pragma once
//p2_hash.h
//Joseph DePoyster
//COSC 2030
//May 2nd, 2018

/*	
	Contains parts 4 - 5 of project 2. This includes:
		-Text to int hash function (~line 27)
		(slashHash is what I would wish to be graded for part 4. 
		-Another hash for the bloom filter(~line 50)
		-Bloom filter function (~line 73)
*/		

#include <iostream>
#include <vector>
#include <string>
using namespace std;

//slashHash function 
//Joseph DePoyster
//May 2nd, 2018
//converts a string of less than 80 characters to an int valued hash
//named after the fact that it slashes a big number into a smaller number. 
//
int slashHash(string input)
{
	if (input.size() > 80)
	{
		return -1;
	}
	int hash = 2147483647;
	int tool = 0;
	int firstLetter = input[0];
	for (int i = 0; i < input.size(); i++)
	{
		tool = tool + input[i];
	}
	tool = tool * tool;
	hash = (hash / tool) % firstLetter;

	return hash;
}

//simpleHash function
//Joseph DePoyster
//May 3rd
//converts string of less than 80 characters to an int valued hash
int simpleHash(string input)
{
	if (input.size() > 80)
	{
		return -1;
	}
	int hash = 0;
	int tool = 0;
	int firstLetter = input[0];
	for (int i = 0; i < input.size(); i++)
	{
		tool = tool + input[i];
	}
	hash = tool % input.size();
	return hash;
}

//bloom filter structure
//Joseph DePoyster
//May 3rd, 2018
//implementation of a simple bloom filter that uses only two different hash functions
//hash functions used convert strings to integers
//both hash function's hashes are valued less than 200 (highest hash I got from slashHash was 117)
struct bloomFilter
{
public:
	bloomFilter();
	void add(string s);
	bool ask(string s);
private:
	bool bits[200];
};

bloomFilter::bloomFilter()
{
	for (int i = 0; i < 200; i++)
	{
		bits[i] = false;
	}
}

void bloomFilter::add(string s) //sets position of hashes in the array to true. 
{
	int hash1 = slashHash(s);
	int hash2 = simpleHash(s);

	if (bits[hash1] == false)
	{
		bits[hash1] = true; //stores true for the location of the hash if it is false. 
		//if the location is already true, than it will stay that way. 
	}
	if (bits[hash2] == false)
	{
		bits[hash2] = true; //ditto
	}
}

bool bloomFilter::ask(string s)//checks to see if location of 
{
	int hash1 = slashHash(s);
	int hash2 = simpleHash(s);
	bool condition = false;

	if (bits[hash1] == true && bits[hash2] == true)
	{
		condition = true;//returning true means there is a possibility that the input string is in the boom filter
	}					 //returning false means the string definitly does not belong to the set.
	return condition;
}