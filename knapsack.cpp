//v is a vector of value, w is a vector of weight, n is the length of the previous vector, W is a vector from 0 to W
//KnapSack(v, w, n, W)
//{
//	for (w = 0 to W) V[0, w] = 0;
//
//	for (i = 1 to n)
//		for (w = 0 to W)
//			if (w[i] <= w)
//				V[i, w] = max{ V[i - 1,w],vi + V[i - 1,w - wi] }
//			else
//				V[i, w] = V[i - 1, w]
//	return V[n, W]
//}

// A Dynamic Programming based solution for 0-1 Knapsack problem
#include<stdio.h>
#include<vector>
#include <iostream>
using namespace std;
// A utility function that returns maximum of two integers
int max(int a, int b) { return (a > b) ? a : b; }

// Returns the maximum value that can be put in a knapsack of capacity W
vector<bool> knapSack(int W, int wt[], int val[], int n, int& maxVal)
{
	int i, w;
	vector<vector<int>> Value(n+1,vector<int>(W+1));
	vector<vector<int>> Keep(n + 1, vector<int>(W + 1));

	int comp1 = 0;
	int comp2 = 0;
	// Build table K[][] in bottom up manner
	for (i = 0; i <= n; i++)
	{
		for (w = 0; w <= W; w++)
		{
			if (i == 0 || w == 0)
			{
				Value[i][w] = 0;
				Keep[i][w] = 0;
			}
			else if (wt[i - 1] <= w)
			{
				comp1 = val[i - 1] + Value[i - 1][w - wt[i - 1]];
				comp2 = Value[i - 1][w];
				if (comp1 > comp2)
				{
					Keep[i][w] = 1;
					Value[i][w] = comp1;
				}
				else
				{
					Value[i][w] = comp2;
				}
			}
			else
				Value[i][w] = Value[i - 1][w];
		}
	}

	//Determine which to keep
	w = W;
	i = n;
	vector<bool> keep(n);
	for (int j = 0; j < n; j++)
	{
		keep[j] = false;
	}

	while (i-1)
	{
		if (Keep[i][w])
		{
			keep[i-1] = true;
			//If this one is kept, then the total weight subtract its weight is the remaining weight
			w = w - wt[i-1];
		}
		i--;
	}

	maxVal=Value[n][W];
	return keep;
}

int main()
{
	int val[] = { 60, 100, 120 };
	int wt[] = { 10, 20, 30 };
	int  W = 50;
	int n = sizeof(val) / sizeof(val[0]);

	int maxVal = 0;
	vector<bool> keep = knapSack(W, wt, val, n, maxVal);

	for (int i = 0; i < keep.size(); i++)
	{
		cout<<keep[i]<<" ";
	}
	cout << endl;
	cout << maxVal << endl;



	return 0;
}
