#include <iostream>
#include <random>
#include <vector>
#include "Dice.h"
using namespace std;

Dice::Dice()
{
	sides = 0;
	result = 0;
}

Dice::Dice(int s)
{
	sides = s;
	result = 0;
}

int Dice::roll()
{
	mt19937 g(random_device{}());
	uniform_int_distribution<int> dist(1, sides);
	return result = dist(g);
}

int Dice::roll(int s)
{
	sides = s;

	mt19937 g(random_device{}());
	uniform_int_distribution<int> dist(1, sides);
	return result = dist(g);
}

void Dice::rollVoid()
{
	mt19937 g(random_device{}());
	uniform_int_distribution<int> dist(1, sides);
	result = dist(g);
}

void Dice::displayRoll()
{
	mt19937 g(random_device{}());
	uniform_int_distribution<int> dist(1, sides);
	result = dist(g);

	cout << result << " ";
}

vector<int> Dice::rollMultiple(int amount)
{
	int result = 0;
	vector<int> results;

	for (int i = 0; i < amount; ++i)
	{
		mt19937 g(random_device{}());
		uniform_int_distribution<int> dist(1, sides);
		result = dist(g);
		results.push_back(result);
	}
	return results;
}

vector<int> Dice::rollMultiple(int amount, int s)
{
	sides = s;
	int result = 0;
	vector<int> results;

	for (int i = 0; i < amount; ++i)
	{
		mt19937 g(random_device{}());
		uniform_int_distribution<int> dist(1, sides);
		result = dist(g);
		results.push_back(result);
	}
	return results;
}