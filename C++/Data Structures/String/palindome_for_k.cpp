#include <bits/stdc++.h>
using namespace std;

int lcs(string X, string Y, int m, int n)
{
  int L[m+1][n+1];
  for(int i=0; i<m+1; ++i)
  {
    for(int j=0; j<n+1; ++j)
    {
      if (i==0 || j==0)
      L[i][j]=0;
      else if (X[i-1]==Y[j-1])
      L[i][j] = L[i-1][j-1]+1;
      else
      {
        L[i][j] = max(L[i-1][j], L[i][j-1]);
      }
    }
  }
  return L[m][n];
}

bool iskpal(string str, int k)
{
  int n = str.length();
  if (n==0) return NULL;
  string revStr = str;
  reverse(revStr.begin(), revStr.end());
  int lps = lcs(str, revStr, n, n);
  return n-lps >=k;
}

int main()
{
  string str = "abcdeca";
  int k=2;
  cout<<"iskpal"<<iskpal(str, k);
  return 0;
}
