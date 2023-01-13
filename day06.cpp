#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int start_marker(const int marker_len, string path)
{
	ifstream infile(path.c_str());
	infile.seekg(0, infile.end);
	int len = infile.tellg();
	char marker[20] = "";
	int char2process;
	for (int i = 0; i < len - marker_len; i++)
	{
		infile.seekg(i);
		infile.read(marker, marker_len);
		int j = 0;
		bool no_duplicate = true;
		do
		{
			for (int k = j + 1; k < marker_len; k++)
			{
				if (marker[j] == marker[k])
				{
					no_duplicate = false;
				}
			}
			j++;
		} while (j < marker_len && no_duplicate);
		if (no_duplicate)
		{
			char2process = i + marker_len;
			break;
		}
	}
	return char2process;
}

int main()
{
	string path = "input/day06.txt";
	// string path = "input/test.txt";

	const int sop_len = 4;
	const int som_len = 14;

	int sop = start_marker(sop_len, path);
	int som = start_marker(som_len, path);
	cout << "solution to part 1 is " << sop << endl;
	cout << "solution to part 2 is " << som << endl;

	return 0;
}