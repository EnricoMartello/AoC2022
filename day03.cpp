#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <math.h>

using namespace std;

int main()
{
	string path = "input/day03.txt";
	// string path = "input/test.txt";
	string s, s1, s2, s3;
	int zero[] = {96, 38};
	ifstream infile(path.c_str());
	int items_no, priority;
	priority = 0;

endloop:
	while (getline(infile, s))
	{
		items_no = (int)s.size() / 2;
		// cout << "Elements in rucksack = " << items_no << endl;
		for (int i1 = 0; i1 < items_no; i1++)
		{
			for (int i2 = items_no; i2 < s.size(); i2++)
			{
				if (s[i1] == s[i2])
				{
					priority += int(s[i1] - zero[(int)isupper(s[i1])]);
					// cout << s[i1] << "\t " << priority << endl;
					goto endloop;
				}
			}
		}
	}
	cout << "priority = " << priority << endl;

	infile.clear();
	infile.seekg(0);

	int items_no1, items_no2, items_no3;
	priority = 0;
endloop_part2:
	while (getline(infile, s1))
	{
		getline(infile, s2);
		getline(infile, s3);
		items_no1 = s1.size();
		items_no2 = s2.size();
		items_no3 = s3.size();

		for (int i1 = 0; i1 < items_no1; i1++)
		{
			for (int i2 = 0; i2 < items_no2; i2++)
			{
				if (s1[i1] == s2[i2])
				{
					for (int i3 = 0; i3 < items_no3; i3++)
					{
						if (s1[i1] == s3[i3])
						{
							// cout << "Bingo! " << priority << endl;
							priority += int(s1[i1] - zero[(int)isupper(s1[i1])]);
							goto endloop_part2;
						}
					}
				}
			}
		}
	}

	cout << priority << endl;
	return 0;
}