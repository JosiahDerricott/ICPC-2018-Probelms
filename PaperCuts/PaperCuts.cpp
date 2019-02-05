/*
		Project: ICPC 2018 Problems

		Solved By: Josiah Derricott

		Program Name: Paper Cuts

		Program Purpos: Made to solve the ICPC 2018 Division 2 problem "Paper Cuts"
*/

#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

/*
	The goal here is to take in the input and output strings, condense them down to only unique letters,
	then compare the input vector with the output vector and see which places have mismatches which is where we
	would be cutting
*/
int main()
{
	string input, output;
	int numOfCuts = 0;

	cin >> input >> output; // Get inputs

	vector<char> chIn, chOut;

	for (char c : input) // Populate input vector with every unique char
	{
		if (find(chIn.begin(), chIn.end(), c) != chIn.end())
			continue;

		chIn.push_back(c);
	}

	for (char c : output) // Populate output vector with every unique char
	{
		if (find(chOut.begin(), chOut.end(), c) != chOut.end())
			continue;

		chOut.push_back(c);
	}

	for (int i = 0; i < chIn.size(); i++)
	{
		if ((i + 1) < chIn.size()) // Make sure we don't go out of bounds
		{	
			if (chIn[i + 1] != chOut[i + 1]) // Check next letter in both vectors and see they match, if not, then we must make a cut
			{
				numOfCuts++;
			}
		}
	}

	cout << numOfCuts << endl; // Print result

	system("pause");

	return 0;
}