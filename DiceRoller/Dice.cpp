#include <iostream>
#include <random>
#include <vector>
#include "Dice.h"
using namespace std;
mt19937 g(random_device{}());

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
	uniform_int_distribution<int> dist(1, sides);
	return result = dist(g);
}

int Dice::roll(int s)
{
	sides = s;

	uniform_int_distribution<int> dist(1, sides);
	return result = dist(g);
}

void Dice::rollVoid()
{
	uniform_int_distribution<int> dist(1, sides);
	result = dist(g);
}

void Dice::displayRoll()
{
	uniform_int_distribution<int> dist(1, sides);
	result = dist(g);

	cout << result << " ";
}

vector<int> Dice::rollMultiple(int amount)
{
	vector<int> results;

	for (int i = 0; i < amount; ++i)
	{
		uniform_int_distribution<int> dist(1, sides);
		results.push_back(dist(g));
	}
	return results;
}

vector<int> Dice::rollMultiple(int amount, int s)
{
	sides = s;
	vector<int> results;

	for (int i = 0; i < amount; ++i)
	{
		uniform_int_distribution<int> dist(1, sides);
		results.push_back(dist(g));
	}
	return results;
}