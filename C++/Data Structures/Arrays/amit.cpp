#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
	int a[2][2] = {0};
	int **p;
	cout << typeid(a).name() <<endl;
	cout << typeid(int **).name() << endl;
	return 0;
}
