/*
Rotate a square 2D Matrix by 90 degrees in place
*/

#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <utility>
using namespace std;

void print2DMatrix(vector< vector <int> > &M, int size_x, int size_y)
{
    for (int i = 0; i < size_x; ++i)
    {
      for (int j = 0; j < size_y; ++j)
      {
        cout<<M[i][j]<<" ";
      }
      cout<<endl;
    }
}

void swapRowColIdx(vector< vector<int> > &M, int size_x, int size_y)
{
  int temp = 0;
  int visited[size_x][size_y] ;
  for(int i = 0; i < size_x; ++i )
  {
    for (int j = 0; j < size_y; ++j)
    {
      visited[i][j] = 0;
    }
  }
  for (int i = 0; i <size_x; ++i)
  {
    for (int j = 0; j < size_y; ++j)
    {
      if (visited[i][j] == 0 && visited[j][i] == 0)
      {
        temp = M[i][j];
        M[i][j] = M[j][i];
        M[j][i] = temp;
        visited[i][j] = 1;
        visited[j][i] = 1;
      }
    }
    cout<<endl;
  }
}

void reverse(vector<vector<int>> &M, int j ,int size_x)
{
  int temp;
  for(int i = 0; i < size_x/2; ++i)
  {
      temp = M[i][j];
      M[i][j] = M[size_x - 1 - i][j];
      M[size_x - 1 - i][j] = temp;
  }
}

void reverseCol(vector<vector <int> > &M, int size_x, int size_y)
{
    for(int j = 0; j < size_y; ++j)
    {
      reverse(M, j, size_x);
    }
}

int main()
{
  int size_x = 3;
  int size_y = 3;
  srand(time(0));
  vector<vector <int>> M (size_x, vector<int> (size_y));
  int ctr = 1;
  for (int i = 0; i < size_x; ++i)
  {
    for (int j = 0; j < size_y; ++j)
    {
      M[i][j] = ctr++ ;
    }
  }

  print2DMatrix(M, size_x, size_y);
  swapRowColIdx(M, size_x, size_y);
  cout<<endl;

  reverseCol(M, size_x, size_y);
  print2DMatrix(M, size_x, size_y);
  return 0;
}
