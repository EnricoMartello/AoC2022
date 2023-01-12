#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	string path = "input/day04.txt";
	string pairs;
	string a_low, a_high, b_low, b_high;
	int counter = 0;
	int line = 0;
	ifstream infile(path.c_str());
	bool sections[100];
	for (int i = 0; i < 100; i++)
	{
		sections[i] = false;
	}

	while (getline(infile, a_low, '-') &&
				 getline(infile, a_high, ',') &&
				 getline(infile, b_low, '-') &&
				 getline(infile, b_high))
	{ // get a whole line
		line += 1;
		if (stoi(a_low) <= stoi(b_low) && stoi(a_high) >= stoi(b_high))
		{
			counter += 1;
		}
		else if (stoi(a_low) >= stoi(b_low) && stoi(a_high) <= stoi(b_high))
		{
			counter += 1;
		}
	}
	cout << counter << endl;

	infile.clear();
	infile.seekg(0);
	counter = 0;
	while (getline(infile, a_low, '-') &&
				 getline(infile, a_high, ',') &&
				 getline(infile, b_low, '-') &&
				 getline(infile, b_high))
	{ // get a whole line
		line += 1;
		if (stoi(a_high) < stoi(b_low) || stoi(b_high) < stoi(a_low))
		{
			counter += 1;
		}
	}

	cout << line - counter << endl;
}