#include<iostream>

using namespace std;
int main101001(int argc, char * argv[])
{
	int a;
	int *p;

	a = 100;
	p = &a;

	cout << "*P:" << *p << endl;
	cout << "&P:" << &p << endl;
	cout << "P:" << p << endl;
	cout << "a:" << a << endl;
	cout << "&a:" << &a << endl;

	getchar();


} 