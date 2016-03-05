//Given a group of people with known heights and weights, 
//calculate a combination with maximize number of people involved, 
//while both the heights and weights are reduced from bottom to top,
//and output this combination
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> sortGroup(vector<vector<int>> group, int index)
{
	int len = group.size();

	//Perform a bubble sort based on heights info
	for (int i = len - 1; i > 0;i--)
	{
		for (int j = 0; j < i;j++)
		{
			if(group[j][index]>group[j+1][index])
			{
				int temp_height = group[j][0];
				int temp_weight = group[j][1];

				group[j][0] = group[j + 1][0];
				group[j][1] = group[j + 1][1];

				group[j + 1][0] = temp_height;
				group[j + 1][1] = temp_weight;
			}
		}
	}

	return group;
}


int maxPeople(vector<vector<int>> group)
{
	//Sort based on the first element, which is height in our case
	group=sortGroup(group,0);

	for (int i = 0; i < group.size();i++)
	{
		for (int j = 0; j < group[0].size();j++)
		{
			cout << group[i][j]<<" ";
		}

		cout << endl;
	}

	//Find the max number of people via two loops
	int max_count_temp = 0;
	int max_count_final = 0;
	int temp = 0;
	for (int i = group.size() - 1; i > 1;i--)
	{
		max_count_temp = 0;
		temp = group[i][1];
		for (int j = i - 1; j >= 0;j--)
		{
			if(group[j][1]<=temp)
			{
				max_count_temp++;
				temp = group[j][1];
			}
		}

		if(max_count_temp>max_count_final)
		{
			max_count_final = max_count_temp;
		}
	}


	return max_count_final+1;
}


int main()
{
	vector<vector<int>> group = { {165,55},{175,85},{170,59},{173,73},{178,80} };


	int max = maxPeople(group);

	cout << max << endl;
	return 0;
}