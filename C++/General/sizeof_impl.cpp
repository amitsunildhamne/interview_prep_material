#include <iostream>
#include <cstdio>
using namespace std;

int main()
{

int a;
char *p1,*p2;
p1 = &a;
p2 = (&a)+1;
printf("size of variable is:%d\n", p2 - p1);
}
