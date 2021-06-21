#include "Dice.h"
#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <cmath>
using namespace std;

//Prototypes
void diceInputAnalyzer(const string& input, int& amount, int& sides, int& modifier, char& sign);
int tallyAndModify(vector<int> results, int modifier, char sign);

int main()
{
	Dice dice;
	int amount = 0, sides = 0, modifier = 0;
	char sign = ' ';
	string input;
	vector<int> results;
	
	do {
		//Clearing Variables
		amount = 0, sides = 0, modifier = 0, sign = ' ';
		results.clear();

		//Input Gathering
		cout << "Enter a roll: ";
		getline(cin, input);

		if (input != "stop") {
			//Input Analysis
			diceInputAnalyzer(input, amount, sides, modifier, sign);
			
			//Rolling
			results = dice.rollMultiple(amount, sides);

			//Display Results
			if (sign != ' ')
				cout << "\nResult of " << amount << "d" << sides << " " << sign << " " << modifier << ": " << tallyAndModify(results, modifier, sign) << endl;
			else
				cout << "\nResult of " << amount << "d" << sides << ": " << tallyAndModify(results, modifier, sign) << endl;
			cout << "-------------------------\n";
			for (int i = 0; i < amount - 1; ++i)
				cout << results[i] << ", ";
			if (amount > 0)
			cout << results[amount - 1] << endl << endl;

		}
	} while (input != "stop");
}

void diceInputAnalyzer(const string& input, int& amount, int& sides, int& modifier, char& sign)
{
	vector<char> charInts;
	int size = input.size(), size2 = 0, intCast = 0;
	bool extra = false, d = false;

	for (int i = 0; i < size; ++i)
	{
		//Checks for digit chars to convert to ints
		if (isdigit(input[i]))
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
				amount += (int)charInts[j] * pow(10, (size2 - 1) - j);
			}
			charInts.clear();
			size2 = 0;
			d = true;
		}
		//Looks for an operator to determine whether the extra section is necessary
		//and then stores the sides chars as an int
		else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/')
		{
			if (d == true) {
			sign = input[i];
			for (int j = 0; j < size2; ++j)
			{
				charInts[j] -= '0';
				sides += (int)charInts[j] * pow(10, (size2 - 1) - j);
			}
			charInts.clear();
			size2 = 0;
			extra = true; }
		}
	}
	//Stores sides chars as an int if there's no operator
	if (extra == false)
	{
		for (int j = 0; j < size2; ++j)
		{
			charInts[j] -= '0';
			sides += (int)charInts[j] * pow(10, (size2 - 1) - j);
		}
	}
	//Stores modifier chars as an int if there's an operator
	else if (extra == true)
	{
		for (int j = 0; j < size2; ++j)
		{
			charInts[j] -= '0';
			modifier += (int)charInts[j] * pow(10, (size2 - 1) - j);
		}
	}
}

int tallyAndModify(vector<int> results, int modifier, char sign)
{
	int size = results.size();
	int total = 0;

	for (int i = 0; i < size; ++i)
		total += results[i];

	switch (sign) {

	case '+':
		total += modifier;
		break;
	case '-':
		total -= modifier;
		break;
	case '*':
		total *= modifier;
		break;
	case '/':
		total /= modifier;
		break;
	case ' ':
		break;
	}
	return total;
}