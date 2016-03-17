#include <iostream>

class A
{
private:
	int a;
	int b;

public:
	A():b(0),a(b+2){}//This is wrong!
	void Print()
	{
		std::cout << a << " " << b << std::endl;
	}
};

int main()
{
	A a;
	a.Print();
	return 0;
}