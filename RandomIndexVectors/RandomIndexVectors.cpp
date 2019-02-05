/*
		Project: ICPC Division 2 Problems
		
		Solution By: Josiah Derricott
		
		Program Name: Random Index Vectors

		Program Purpose: To solve the ICPC Division 2 problem "Random Index Vectors"
*/

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> condenseRIV(vector<int> mainVector, bool shouldCondense, int vectorLength);
vector<int> addRIVS(vector<int> firstRIV, vector<int> secondRIV, int length);
vector<int> multiplyRIVS(vector<int> firstRIV, vector<int> secondRIV, int length);
vector<int> rotateRIV(vector<int> rivToRotate, int rotationAmount);
vector<int> populateVector(string input);

int main()
{
	int rivLength = 0;
	int numberToRotate = 0;

	cin >> rivLength >> numberToRotate;

	string firstRIVStr = "";
	string secondRIVStr = "";

	cin.get();

	getline(cin, firstRIVStr);
	getline(cin, secondRIVStr);

	vector<int> firstRIV = condenseRIV(populateVector(firstRIVStr), false, rivLength);
	vector<int> secondRIV = condenseRIV(populateVector(secondRIVStr), false, rivLength);

	vector<int> outputAdd = condenseRIV(addRIVS(firstRIV, secondRIV, rivLength), true, -1);

	for (auto& var : outputAdd)
	{
		cout << var << " ";
	}

	cout << endl;

	vector<int> outputMultiply = condenseRIV(multiplyRIVS(firstRIV, secondRIV, rivLength), true, -1);

	for (auto& var : outputMultiply)
	{
		cout << var << " ";
	}

	cout << endl;

	vector<int> outputRotateFirst = condenseRIV(rotateRIV(firstRIV, numberToRotate), true, -1);

	for (auto& var : outputRotateFirst)
	{
		cout << var << " ";
	}

	cout << endl;

	vector<int> outputRotateSecond = condenseRIV(rotateRIV(secondRIV, numberToRotate), true, -1);

	for (auto& var : outputRotateSecond)
	{
		cout << var << " ";
	}
}

/*
		- Used to condense or uncondense an RIV -
			-> mainVector: the input vector
			-> shouldCondense: determines if it should condense or uncondense a vector.
								False = uncondense, True = condense
			-> vectorLength: used when uncondensing an RIV to know how long it is.
								If -1, will assume largest index is the end.
*/
vector<int> condenseRIV(vector<int> mainVector, bool shouldCondense, int vectorLength)
{
	vector<int> returnResult;
	vector<int> nonZeroIndicieStorage;

	int numOfNonZero = 0;
	int maxIndex = vectorLength > -1 ? vectorLength : abs(mainVector.back());

	switch (shouldCondense)
	{
	case true:
		for (int i = 0; i < mainVector.size(); i++)
		{
			if (mainVector[i] != 0)
			{
				numOfNonZero++;
				nonZeroIndicieStorage.push_back((i + 1) * mainVector[i]);
			}
		}

		returnResult.push_back(numOfNonZero);

		for (auto var : nonZeroIndicieStorage)
		{
			returnResult.push_back(var);
		}

		break;
	case false:
		mainVector.erase(mainVector.begin());

		for (int i = 0; i < maxIndex; i++)
		{
			for (auto& var : mainVector)
			{
				if ((i + 1) == abs(var))
				{
					int num = var < 0 ? -1 : 1;

					returnResult.push_back(num);
					mainVector.erase(find(mainVector.begin(), mainVector.end(), var));

					break;
				}
			}

			if (i >= returnResult.size())
			{
				returnResult.push_back(0);
			}
		}

		break;
	}

	return returnResult;
}

vector<int> populateVector(string input)
{
	vector<int> outputVect;

	int indexTracker = 0;
	int inputVal = 0;
	int nextIndex = 0;

	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] == ' ')
		{
			if (outputVect.empty())
			{
				outputVect.push_back(stoi(input.substr(0, i)));

				indexTracker = i;

				continue;
			}

			nextIndex = input.find(' ', i + 1);

			inputVal = stoi(input.substr(indexTracker, nextIndex));

			outputVect.push_back(inputVal);

			indexTracker = i;

			continue;
		}
		else if (i == (input.length() - 1))
		{
			inputVal = stoi(input.substr(indexTracker, input.back()));

			outputVect.push_back(inputVal);

			break;
		}
	}

	return outputVect;
}

vector<int> addRIVS(vector<int> firstRIV, vector<int> secondRIV, int length)
{
	vector<int> result;

	for (int i = 0; i < length; i++)
	{
		short firstNum = firstRIV[i];
		short secondNum = secondRIV[i];

		if (firstNum == secondNum)
		{
			result.push_back(firstNum);

			continue;
		}

		result.push_back((firstNum + secondNum));
	}

	return result;
}

vector<int> multiplyRIVS(vector<int> firstRIV, vector<int> secondRIV, int length)
{
	vector<int> result;

	for (int i = 0; i < length; i++)
	{
		result.push_back((firstRIV[i] * secondRIV[i]));
	}

	return result;
}

vector<int> rotateRIV(vector<int> rivToRotate, int rotationAmount)
{
	vector<int> result = rivToRotate;

	for (int i = 0; i < rotationAmount; i++)
	{
		int nextVar = result[0];

		result.erase(result.begin());

		result.push_back(nextVar);
	}

	return result;
}