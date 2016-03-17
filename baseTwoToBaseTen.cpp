#include <iostream>

using namespace std;

int main()
{
	int n = 19;

	int quotient = 0;
	int remainder = 0;

	char* output = new char[256];
	int i = 0;

	bool flag=false;//label the case as general or oplynomial of 2
	//Case that the number is already polynomial of 2
	while (n>>1)
	{
		if (flag||!(n&(n - 1)))//bitwise and, if it is 0, then all the output except the last one are equal to 0
		{
				output[i] = '0';
				n = n>>1;
				i++;
				flag = true;
		}
		else//General case
		{
			//n==n>>1<<1 if the last digit of n is 0, otherwise n would not be the same after this operation
			if (n == n >> 1 << 1)
			{
				output[i] = '0';
			}
			else
			{
				output[i] = '1';
			}
			

			n = n>>1;
			i++;
		}
	}

	output[i] = '1';
	i++;
	output[i] = '\0';

	string out = output;

	cout << out.length() << " " << sizeof(output) << " "<< sizeof(output[0]) << " "<<sizeof(output) / sizeof(output[0]) << endl;
	int j = out.length()-1;
	for (int i = 0; i < sizeof(output); i++)
	{
		output[i] = out[j];
		j--;
	}

	cout << output << endl;


	//int pow = 0;
	//int curr_digit = 0;

	////First must calculate the biggest pow where n=2^pow+2^pow-1...
	//int factor = n;
	//while (1)
	//{
	//	//Shift to right until there is nothing
	//	factor = factor>>1;
	//	//the max power, for example n=8, then it will be 3, but here it is 3+1=4
	//	pow++;
	//	if (!factor)
	//	{
	//		break;
	//	}
	//}
	//char* output = new char[pow];
	//n = n - 2 ^ (pow-1);

	//int entry=0;
	//output[entry] = '1';

	//curr_digit = pow-1;
	//while (n&(n - 1))
	//{

	//	curr_digit--;
	//	entry++;
	//}

	//for (; curr_digit > 0; curr_digit--)
	//{
	//	output[entry] = '0';
	//	entry++;
	//}

	//cout << pow << endl;


	return 0;
}