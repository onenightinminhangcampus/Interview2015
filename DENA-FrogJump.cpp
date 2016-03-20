//Ladder problem
//There are n ladders
//You can jump 1,2 or 3 one time
//How many possiblities are there

#include <iostream>
using namespace std;
int possiblities(int n)
{
	if (n == 1)
	{
		return 1;
	}
	else if (n == 2)
	{
		return 1;
	}
	else if (n == 3)
	{
		return 2;
	}
	else
	{
		return possiblities(n - 1) + possiblities(n - 2) + possiblities(n - 3);
	}

}

int main()
{
	int n = 33;
	
	int total = possiblities(n);

	cout << total << endl;
	return 0;
}
