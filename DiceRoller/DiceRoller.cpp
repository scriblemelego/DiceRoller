#include "Dice.h"
#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <cmath>
using namespace std;

//Prototypes
void diceInputAnalyzer(const string& input, int& amount, int& sides, int& modifier, char& sign);

int main()
{
	Dice dice;
	int amount = 0, sides = 0, modifier = 0;
	char sign = ' ';
	string input;
	vector<int> results;
	
	do {
		//Input Gathering
		cout << "Enter a roll: ";
		getline(cin, input);

		if (input != "stop") {
			//Input Analysis
			diceInputAnalyzer(input, amount, sides, modifier, sign);

			//Rolling
			results = dice.rollMultiple(amount, sides);

			//Display Results
			for (int i = 0; i < amount; ++i)
				cout << results[i] << " ";
			cout << endl;
			results.clear();
		}
	} while (input != "stop");
}

void diceInputAnalyzer(const string& input, int& amount, int& sides, int& modifier, char& sign)
{
	vector<char> charInts;
	int size = input.size(), size2 = 0, intCast = 0;
	bool extra = false;

	amount = 0, sides = 0, modifier = 0;

	for (int i = 0; i < size; ++i)
	{
		//Checks if space or other whitespace to skip
		if (isblank(input[i])) {}

		//Checks for digit chars to convert to ints
		else if (isdigit(input[i]))
		{
			charInts.push_back(input[i]);
			++size2;
		}
		//Looks for the d to determine where dice amount entry ends and where dice value entry begins
		//and then stores the amount chars as an int
		else if (input[i] == 'd' || input[i] == 'D')
		{
			for (int j = 0; j < size2; ++j)
			{
				charInts[j] -= '0';
				amount += static_cast<int>(charInts[j]) * pow(10, (size2 - 1) - j);
			}
			charInts.clear();
			size2 = 0;
		}
		//Looks for an operator to determine whether the extra section is necessary
		//and then stores the sides chars as an int
		else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/')
		{
			sign = input[i];
			for (int j = 0; j < size2; ++j)
			{
				charInts[j] -= '0';
				sides += static_cast<int>(charInts[j]) * pow(10, (size2 - 1) - j);
			}
			charInts.clear();
			size2 = 0;
			extra = true;
		}
	}
	//Stores sides chars as an int if there's no operator
	if (extra == false)
	{
		for (int j = 0; j < size2; ++j)
		{
			charInts[j] -= '0';
			sides += static_cast<int>(charInts[j]) * pow(10, (size2 - 1) - j);
		}
	}
	//Stores modifier chars as an int if there's an operator
	else if (extra == true)
	{
		for (int j = 0; j < size2; ++j)
		{
			charInts[j] -= '0';
			modifier += static_cast<int>(charInts[j]) * pow(10, (size2 - 1) - j);
		}
	}
}

