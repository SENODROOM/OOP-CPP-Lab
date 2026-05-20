#include <iostream>
using namespace std;

int main()
{
	int a, b, c;
	cout << "Enter a: ";
	cin >> a;
	cout << "Enter b: ";
	cin >> b;
	c = a + b;

	int *ptra = &a;
	int *ptrb = &b;
	int *ptrc = &c;
	cout << "Memory address a: " << ptra << endl;
	cout << "Memory address b: " << ptrb << endl;
	cout << "Memory address c: " << ptrc << endl;
	cout << "Value of a: " << *ptra << endl;
	cout << "Value of b: " << *ptrb << endl;
	cout << "Value of c: " << *ptrc << endl;
	return 0;
}
