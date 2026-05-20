#include <iostream>
using namespace std;

void swapping(int &a, int &b)
{
	int temp = b;
	b = a;
	a = temp;
}

int main()
{
	int a, b;
	cout << "Enter a: ";
	cin >> a;
	cout << "Enter b: ";
	cin >> b;

	swapping(a, b);

	cout << "a= " << a << endl;
	cout << "b= " << b << endl;

	return 0;
}
