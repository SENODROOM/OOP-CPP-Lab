#include <iostream>
using namespace std;

int *resetToZero(int *p);

int main()
{
	int a;
	cout << "Enter a: ";
	cin >> a;
	int *ptr = &a;
	int *newptr = resetToZero(ptr);

	cout << "newptr= " << *newptr << endl;
	return 0;
}

int *resetToZero(int *p)
{
	*p = 0;
	return p;
}