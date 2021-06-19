#pragma once
using namespace std;
class Dice;

class Dice
{
private:
	int sides;
	int result;
public:
	Dice();
	Dice(int s);

	void setSides(int s) { sides = s; }
	void setResult(int r) { result = r; }
	int getSides() { return sides; }
	int getResult() { return result; }

	int roll();
	void rollVoid();
	void displayRoll();
};