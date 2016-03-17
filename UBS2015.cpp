//Reverse the words in a string
//"hello world" reversed to "world hello"
#include <iostream>
#include <string>
using namespace std;

string reverseString(string a)
{
	int j = a.length()-1;
	char tmp;
	//a[i] is exchanging with the last value first, so it is a[a.length()-1] instead of a[a.length()]
	for (int i = 0; i < j; i++)
	{
		tmp = a[i];
		a[i] = a[j];
		a[j] = tmp;
		j--;
	}
	return a;
}

int main()
{
	string a = "It is an idyllic new England day";
	
	a = reverseString(a);

	int j = 0;
	int flag=0;
	int tmp;
	for (int i = 0; i <= a.length(); i++)
	{
		//a[i] is whitespace or a[i] is at the one position after the last value
		if(a[i]==' '||!a[i])
		{
			//Reverse the word here
			int l = i-1;
			for (int k=j; k < l; k++)
			{
				tmp = a[k];
				a[k] = a[l];
				a[l] = tmp;
				l--;
			}

			j = i+1;
		}
	}

	cout << a << endl;


	return 0;
}
