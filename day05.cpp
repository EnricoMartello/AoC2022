#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	string path = "input/day05.txt";
	// string path = "input/test.txt";
	string s, crates_no, stack_from, stack_to;
	bool movement_list = false;
	ifstream infile(path.c_str());

	getline(infile, s);
	int tot_stack = (int)(1 + s.size()) / 4; // total no stacks
	// cout << "tot_stack = " << tot_stack << endl;
	//* Creating an array with dynamic allocation
	string *stacks = (string *)malloc(tot_stack * sizeof(string));
	string *stacks2 = (string *)malloc(tot_stack * sizeof(string));

	infile.clear();
	infile.seekg(0);

	int j = 0, stack = 0;
	while (getline(infile, s) && movement_list == false)
	{
		if (s.empty())
		{
			movement_list = true;
			goto endloop;
		}
		for (int i = 1; i < s.size(); i += 4)
		{
			if (isspace(s[i]))
			{
				stack++;
			}
			else
			{
				stacks[stack].push_back(s[i]);
				stack++;
			}
		}
		stack = 0;
	}

endloop:
	for (int j = 0; j < 9; j++)
	{
		stacks[j].pop_back();
		stacks2[j] = stacks[j];
	}
	// get current read position
	auto read_pos = infile.tellg();

	while (getline(infile, s, ' ') && getline(infile, crates_no, ' ') && getline(infile, s, ' ') && getline(infile, stack_from, ' ') && getline(infile, s, ' ') && getline(infile, stack_to))
	{
		for (int j = 0; j < stoi(crates_no); j++)
		{
			stacks[stoi(stack_to) - 1].insert(stacks[stoi(stack_to) - 1].begin(), stacks[stoi(stack_from) - 1][0]);
			stacks[stoi(stack_from) - 1].erase(stacks[stoi(stack_from) - 1].begin(), stacks[stoi(stack_from) - 1].begin() + 1);
		}
	}

	infile.clear();
	infile.seekg(read_pos);

	while (getline(infile, s, ' ') && getline(infile, crates_no, ' ') && getline(infile, s, ' ') && getline(infile, stack_from, ' ') && getline(infile, s, ' ') && getline(infile, stack_to))
	{
		string moving_block = stacks2[stoi(stack_from) - 1].substr(0, stoi(crates_no));
		stacks2[stoi(stack_to) - 1].insert(0, moving_block, 0);
		stacks2[stoi(stack_from) - 1].erase(stacks2[stoi(stack_from) - 1].begin(), stacks2[stoi(stack_from) - 1].begin() + stoi(crates_no));
	}

	cout << "Part 1: " << endl;
	for (int j = 0; j < tot_stack; j++)
	{
		cout << stacks[j][0];
	}
	cout << endl;

	cout << "Part 2: " << endl;
	for (int j = 0; j < tot_stack; j++)
	{
		cout << stacks2[j][0];
	}
	cout << endl;

	free(stacks);
	return 0;
}
