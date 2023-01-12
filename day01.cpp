#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <math.h>

using namespace std;

int main()
{
	string path = "input/day01.txt";
	// string path = "input/test.txt";
	string s;
	ifstream infile(path.c_str());

	int cal;
	int elf_no = 1;
	int elf_index = 0;

	while (getline(infile, s))
	{
		if (s.empty())
		{
			// cout<< "empty line!" <<endl;
			elf_no += 1;
		}
	}
	int *elf_cals = (int *)malloc(elf_no * sizeof(int));
	infile.clear();
	infile.seekg(0);

	cout << "\nThere are " << elf_no << " elves!\n"
			 << endl;

	while (getline(infile, s))
	{
		if (s.empty())
		{
			elf_index += 1;
		}
		else
		{
			// cout<< s <<endl;
			elf_cals[elf_index] += stoi(s);
		}
	}

	int max = 0;
	for (int j = 0; j < elf_no; j++)
	{
		// cout << elf_cals[j] << endl;
		if (elf_cals[j] > max)
		{
			max = elf_cals[j];
		}
	}

	// Part 1

	// cout << max << endl;

	// part 2
	// for (int j = 0; j < elf_no; j++)
	// {
	// 	cout << elf_cals[j] << endl;
	// }
	// cout << "\n"
	// 		 << endl;

	sort(elf_cals, elf_cals + elf_no, greater<int>());

	// for (int j = 0; j < elf_no; j++)
	// {
	// 	cout << elf_cals[j] << endl;
	// }
	cout << elf_cals[0] + elf_cals[1] + elf_cals[2] << endl;

	return 0;
}