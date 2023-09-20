#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	const int forest_size = 99;
	int forest[forest_size][forest_size];
	int scenic_score[forest_size][forest_size] = {0};
	bool visibles[forest_size][forest_size] = {false};
	string s;
	string path = "input/day08.txt";
	// string path = "input/test.txt";
	ifstream infile(path.c_str());
	int j = 0;
	while (getline(infile, s))
	{
		// cout << s << endl;
		for (int i = 0; i < forest_size; i++)
		{
			forest[j][i] = int(s[i]) - 48;
		}
		j++;
	}

	cout << "Forest: " << endl;

	for (int i = 0; i < forest_size; i++)
	{
		for (int j = 0; j < forest_size; j++)
		{
			cout << forest[i][j];
		}
		cout << "\n";
	}

	for (int i = 0; i < forest_size; i++)
	{
		visibles[i][0] = 1;
		visibles[0][i] = 1;
		visibles[i][forest_size - 1] = 1;
		visibles[forest_size - 1][i] = 1;
	}

	// Checking from the left
	for (int i = 1; i < forest_size - 1; i++)
	{
		int hightree = forest[i][0];
		for (int j = 1; j < forest_size - 1; j++)
		{
			visibles[i][j] = max(visibles[i][j], (forest[i][j] > hightree));
			hightree = max(hightree, forest[i][j]);
			if (hightree == 9)
			{
				break;
			}
		}
	}

	// Checking from the right
	for (int i = 1; i < forest_size - 1; i++)
	{
		cout << "inspecting row " << i << ":" << endl;
		int hightree = forest[i][forest_size - 1];
		for (int j = forest_size - 1; j > 0; j--)
		{
			visibles[i][j] = max(visibles[i][j], (forest[i][j] > hightree));
			hightree = max(hightree, forest[i][j]);
			if (hightree == 9)
			{
				break;
			}
		}
	}

	// Checking from the top
	for (int j = 1; j < forest_size - 1; j++)
	{
		int hightree = forest[0][j];
		for (int i = 1; i < forest_size - 1; i++)
		{
			visibles[i][j] = max(visibles[i][j], (forest[i][j] > hightree));
			hightree = max(hightree, forest[i][j]);
			if (hightree == 9)
			{
				break;
			}
		}
	}

	// Checking from the bottom
	for (int j = 1; j < forest_size - 1; j++)
	{
		int hightree = forest[forest_size - 1][j];
		for (int i = forest_size - 1; i > 0; i--)
		{
			visibles[i][j] = max(visibles[i][j], (forest[i][j] > hightree));
			hightree = max(hightree, forest[i][j]);
			if (hightree == 9)
			{
				break;
			}
		}
	}

	cout << "\nVisibles: " << endl;

	for (int i = 0; i < forest_size; i++)
	{
		for (int j = 0; j < forest_size; j++)
		{
			cout << visibles[i][j];
		}
		cout << "\n";
	}

	int result = 0;

	for (int i = 0; i < forest_size; i++)
	{
		for (int j = 0; j < forest_size; j++)
		{
			result += visibles[i][j];
		}
	}

	cout << "Visible trees " << result;

	for (int i = 1; i < forest_size - 1; i++)
	{
		for (int j = 1; j < forest_size - 1; j++)
		{
			int dist = 0;
			if (visibles[i][j])
			{
				// Look up
				for (int u = i - 1; u >= 0; u--)
				{
					dist += 1;
					if (forest[i][j] <= forest[u][j])
					{
						break;
					}
				}
				scenic_score[i][j] = dist;
				dist = 0;

				// Look left
				for (int l = j - 1; l >= 0; l--)
				{
					dist += 1;
					if (forest[i][j] <= forest[i][l])
					{
						break;
					}
				}
				scenic_score[i][j] *= dist;
				dist = 0;

				// Look down
				for (int d = i + 1; d < forest_size; d++)
				{
					dist += 1;
					if (forest[i][j] <= forest[d][j])
					{
						break;
					}
				}
				scenic_score[i][j] *= dist;
				dist = 0;

				// Look right
				for (int r = j + 1; r < forest_size; r++)
				{
					dist += 1;
					if (forest[i][j] <= forest[i][r])
					{
						break;
					}
				}
				scenic_score[i][j] *= dist;
				dist = 0;
			}
		}
	}

	cout << "\nScenic score: " << endl;
	int max_score = 1;

	for (int i = 0; i < forest_size; i++)
	{
		for (int j = 0; j < forest_size; j++)
		{
			// cout << scenic_score[i][j];
			max_score = max(max_score, scenic_score[i][j]);
		}
		// cout << "\n";
	}
	cout << "Maximum scenic score: " << max_score << endl;
}