//Game
//Jeff loves playing games, Gluttonous snake(an old game in NOKIA era) is one of his favourites.However, after playing gluttonous snake so many times, he finally got bored with the original rules.
//
//In order to bring new challenge to this old game, Jeff introduced new rules :
//
//The ground is a grid, with n rows and m columns(1 <= n, m <= 500).
//Each cell contains a value v(-1 ≤ vi≤  99999), if v is - 1, then this cell is blocked, and the snake can not go through, otherwise, after the snake visited this cell, you can get v point.
//The snake can start from any cell along the left border of this ground and travel until it finally stops at one cell in the right border.
//During this trip, the snake can only go up / down / right, and can visit each cell only once.
//Special cases :
//
//a.Even in the left border and right border, the snake can go up and down b.When the snake is at the top cell of one column, it can still go up, which demands the player to pay all current points, then the snake will be teleported to the bottom cell of this column and vice versa.
//
//After creating such a new game, Jeff is confused how to get the highest score.Please help him to write a program to solve this problem.
//
//Input
//
//The first line contains two integers n(rows) and m(columns), (1 <= n, m <= 500), separated by a single space.
//
//Next n lines describe the grid.Each line contains m integers vi(-1 ≤ vi ≤ 99999) vi = -1 means the cell is blocked.
//
//Output
//
//Output the highest score you can get.If the snake can not reach the right side, output - 1.
//
//Limits
//
//Memory limit per test : 256 megabytes
//Time limit per test : The faster the better
//Compile & Environment
//
//C++
//
//g++ Main.cc - o Main - fno - asm - Wall - lm--static - std = c++0x - DONLINE_JUDGE
//
//Input
//4 4
//- 1 4 5 1
//2 - 1 2 4
//3 3 - 1 3
//4 2 1 2
//output
//23
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	vector<vector<int>> matrix(n, vector<int>(m));
	for (int i = 0; i < n;i++)
	{
		for (int j = 0; j < m;j++)
		{
			int val;
			cin >> val;
			matrix[i][j] = val;
		}
	}

	//int n = 4, m = 4;
	//vector<vector<int>> matrix(n, vector<int>(m));
	//int i = 0, j = 0;
	//matrix[i][j] = -1;
	//j++;
	//matrix[i][j] = 4;
	//j++;
	//matrix[i][j] = 5;
	//j++;
	//matrix[i][j] = 1;

	//j = 0; i++;
	//matrix[i][j] = 2;
	//j++;
	//matrix[i][j] = -1;
	//j++;
	//matrix[i][j] = 2;
	//j++;
	//matrix[i][j] = 4;

	//j = 0; i++;
	//matrix[i][j] = 3;
	//j++;
	//matrix[i][j] = 3;
	//j++;
	//matrix[i][j] = -1;
	//j++;
	//matrix[i][j] = 3;

	//j = 0; i++;
	//matrix[i][j] = 4;
	//j++;
	//matrix[i][j] = 2;
	//j++;
	//matrix[i][j] = 1;
	//j++;
	//matrix[i][j] = 2;

	vector<vector<int>> values(n, vector<int>(m + 1));
	//Increment the values based on col
	//the initial column of values has all 0
	for (int i = 0; i < n;i++)
	{
		values[i][0] = 0;
	}


	vector<int> tmp(n);
	vector<int> ini(n);
	//traverse through all columns
	for (int col = 1; col < m + 1;col++)
	{
		//moving right
		//get the initial value of this col
		for (int row = 0; row < n;row++)
		{
			if (matrix[row][col-1]==-1)
			{
				values[row][col] = -1;
			}
			else if (values[row][col-1]==-1)
			{
				values[row][col] = matrix[row][col - 1];
			}
			else
			{
				values[row][col] = values[row][col - 1] + matrix[row][col - 1];
			}
			ini[row] = values[row][col];
			tmp[row] = values[row][col];
		}
		//-1 2 3 4

		//Then operate on the initial value values[row][col]
		//path on a column can only be pointing up or pointing down

		//Every entry going up/down generate a unique tmp col based on the same initial value values[row][col]
		//Get the largest of each entry and store in tmp[row], assign it to values[row][col] in the end

		//moving down
		//Every step is supposing that we start from one entry and going down until -1 or return to the original entry after teleport
		for (int row = 0; row < n;row++)
		{
			//row=1
			//tmp: -1 2 3 4
			for (int tmp_row = 0; tmp_row < n; tmp_row++)
			{
				tmp[tmp_row] = matrix[tmp_row][col-1];
			}
			tmp[row] = ini[row];

			if (tmp[row]==-1)
			{
				continue;
			}

			//last=1
			int last = row;
			for (int ind = row+1;;ind++)
			{
				//ind=2
				//ind=3
				//ind=0
				ind = (ind + n) % n;

				if (tmp[ind]==-1||ind==row)
				{
					break;
				}

				//teleported, need to pay all of the points
				if (abs(ind-last)==1)
				{
					tmp[ind] += tmp[last];
				}
				//tmp: -1 2 5 9

				last = ind;
				//last=2
				//last=3
			}


			for (int tmp_row = 0; tmp_row < n; tmp_row++)
			{
				if (tmp[tmp_row]>values[tmp_row][col])
				{
					values[tmp_row][col] = tmp[tmp_row];
				}
			}

		}


		//moving up
		for (int row = 0; row < n; row++)
		{
			for (int tmp_row = 0; tmp_row < n; tmp_row++)
			{
				tmp[tmp_row] = matrix[tmp_row][col - 1];
			}
			tmp[row] = ini[row];

			if (tmp[row] == -1)
			{
				continue;
			}

			int last = row;
			for (int ind = row - 1;; ind--)
			{
				ind = (ind + n) % n;

				if (tmp[ind] == -1 || ind == row)
				{
					break;
				}

				//teleported, need to pay all of the points
				if (abs(ind - last) == 1)
				{
					tmp[ind] += tmp[last];
				}

				last = ind;

			}


			for (int tmp_row = 0; tmp_row < n; tmp_row++)
			{
				if (tmp[tmp_row]>values[tmp_row][col])
				{
					values[tmp_row][col] = tmp[tmp_row];
				}
			}

		}


	}

	int largest = 0;
	for (int row = 0; row < n;row++)
	{
		largest = max(largest, values[row][m]);
	}

	cout << largest << endl;
	//cin.get();

}