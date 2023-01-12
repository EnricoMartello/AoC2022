#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <math.h>

using namespace std;

int main()
{
	string path = "input/day02.txt";
	// string path = "input/test.txt";

	string s;
	ifstream infile(path.c_str());

	string opponent, me, result;
	int points = 0;

	while (infile >> opponent >> me)
	{
		// cout << "your opponent choice is " << opponent << " and you choose " << me << endl;
		if (opponent == "A")
		{
			if (me == "X")
			{
				points += 4;
			}
			else if (me == "Y")
			{
				points += 8;
			}
			else
			{
				points += 3;
			}
		}
		else if (opponent == "B")
		{
			if (me == "Y")
			{
				points += 5;
			}
			else if (me == "Z")
			{
				points += 9;
			}
			else
			{
				points += 1;
			}
		}
		else if (opponent == "C")
		{
			if (me == "Z")
			{
				points += 6;
			}
			else if (me == "X")
			{
				points += 7;
			}
			else
			{
				points += 2;
			}
		}

		else
		{
			cout << opponent << endl;
		}
	}
	cout << points << endl;

	infile.clear();
	infile.seekg(0);

	/*
	Rock = 1
	Paper = 2
	Scissor = 3

	*/
	points = 0;
	while (infile >> opponent >> result)
	{
		if (opponent == "A")
		{
			if (result == "X")
			{
				points += 3;
			}
			else if (result == "Y")
			{
				points += 3;
				points += 1;
			}
			else
			{
				points += 6;
				points += 2;
			}
		}
		else if (opponent == "B")
		{
			if (result == "X")
			{
				points += 1;
			}
			else if (result == "Y")
			{
				points += 3;
				points += 2;
			}
			else
			{
				points += 6;
				points += 3;
			}
		}
		else if (opponent == "C")
		{
			if (result == "X")
			{
				points += 2;
			}
			else if (result == "Y")
			{
				points += 3;
				points += 3;
			}
			else
			{
				points += 6;
				points += 1;
			}
		}

		else
		{
			cout << opponent << endl;
		}
	}
	cout << points << endl;

	return 0;
}