#include <iostream>
#include <cstring>
using namespace std;

void rev(char* c, int start, int end)
{
  int n = end - start + 1;
  for(int i= start; i<n/2;++i )
  swap(c[i], c[n-i-1]);
}


int main()
{
  char c[] = "Amit Dhamne";
  rev(c, 0, strlen(c)-1);
cout<<c<<endl;
}
