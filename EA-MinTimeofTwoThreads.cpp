//{1 1 2 3} Four tasks, each of them cost 1 1 2 3 time unit
//4 Now distribute the four tasks on 2 threads, the lease time that required to perform them

//4 Number of tasks
//1 1 2 3 costs of tasks
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int N;
	cin >> N;

	vector<int> vec(N);
	for (int i = 0; i < N; i++)
	{
		cin >> vec[i];
	}

	//Sort the time of each task in a ascending order
	sort(vec.begin(), vec.end());

	int leftTime=0;
	int rightTime = 0;
	int isLeft=1;
	int n = N-1;
	//traversing from the biggest value
	while (n+1)
	{
		//If right now taks on Left thread has less time, then leftTime add the new value 
		if (isLeft)
		{
			leftTime += vec[n];
		}
		else
		{
			rightTime += vec[n];
		}

		//If leftTime greater than rightTime, then in the next round, the task will be added to the right thread
		if (leftTime > rightTime)
		{
			isLeft = 0;
		}
		else
		{
			isLeft = 1;
		}
	
		n--;
	}
	cout << leftTime << endl;

	cin.get();
	return 0;
}
