#pragma once
#pragma once
//p2_hash.h
//Joseph DePoyster
//COSC 2030
//May 2nd, 2018

/*	
	Contains parts 4 - 5 of project 2. This includes:
		-Text to int hash function (~line ??????????????????????????????????????????????
		(slashHash is what I would wish to be graded for part 4. 
		-Another hash for the bloom filter(~line ?????????????????????????????????????????
		-Bloom filter function (~line ????????????????????????????????????????????
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
	hash = tool % 10;
}

//bloom filter function
//Joseph DePoyster
//May 3rd, 2018
//implementation of a simple bloom filter that uses only two different hash functions
