//Input
//8 Total docs
//3 Number of modified docs
//1 2 8 Modifed docs #
//4 number of links
//1 2 Linked docs #
//2 4
//4 5
//7 8
//Output
//1 2 4 5 7 8 All affected docs
#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<class T>
void print_vector(vector<T> vec)
{
	cout << "Vector: " << endl;
	vector<T>::iterator i = vec.begin();
	while (i != vec.end())
	{
		//get the value using *i
		cout << *i<<" ";
		i++;
	}
	cout << endl<<endl;
}

template<class T>
void print_matrix(vector<vector<T>> matrix)
{
	cout << "Matrix: " << endl;
	vector<vector<T>>::iterator row;
	vector<T>::iterator col;
	for (row = matrix.begin(); row != matrix.end(); row++)
	{
		for (col = row->begin(); col != row->end(); col++)
		{
			//remember get the value using *col
			cout << *col<<" ";
		}
		cout << endl;
	}
	cout << endl<<endl;
}

int main()
{
	int N;
	cin >> N;

	//number of modified
	int nm;
	cin >> nm;

	//Set a flag vector, filled with false
	vector<bool> vec;
	vec.resize(N);
	fill(vec.begin(), vec.end(), false);

	//First the flag corresponding to the modified files are all set to be true
	for (int i = 0; i < nm; i++)
	{
		int tmp;
		cin >> tmp;
		vec[tmp-1] = true;
	}

	//Number of pairs that are linked
	int pairs;
	cin >> pairs;
	//create a matrix that stores the link between two values
	//If two values are linked, then it is stored as 1, otherwise 0
	vector< vector<bool> > matrix(N, vector<bool>(N));
	for (int i = 0; i < pairs; i++)
	{
		int row=0;
		int col=0;
		cin >> row;
		cin >> col;
		matrix[row - 1][col - 1]=true;
		//store the flag matrix as a symmetric matrix so that the order of the two linked values does not matter
		matrix[col - 1][row - 1] = true;
	}


	print_vector(vec);
	print_matrix(matrix);

	for (int i = 0; i < N; i++)
	{
		if (vec[i])
		{
			int searchingRow = i;
			vector<vector<bool>>::iterator rowIter = matrix.begin();
			rowIter = rowIter + searchingRow;
			int searchingCol=0;
			for (vector<bool>::iterator colIter = rowIter->begin(); colIter != rowIter->end(); colIter++)
			{
				if (*colIter&&!vec[searchingCol])
				{
					vec[searchingCol] = true;
					break;
				}
				searchingCol++;
			}
		}
	}

	print_vector(vec);

	int pos = 1;
	for (vector<bool>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		if (*it)
		{
			cout << pos << " ";
		}
		pos++;
	}
	cout << endl;

	cin.get();
	return 0;
}