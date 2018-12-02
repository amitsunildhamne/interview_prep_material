#include <iostream>
#include <queue>
#include <ctime>
#include <cstdlib>
using namespace std;

class QItem
{
public:
  int row;
  int col;
  QItem(int row, int col)
  {
    this->row = row;
    this->col = col;
  }
};

/*void createMatrix(int M[][10], int size_x, int size_y)
{
  for ( int i = 0; i < size_x; ++i )
  {
    for ( int j = 0; j < size_y; ++j )
    {
      M[i][j] = rand()%100;
      cout<<M[i][j]<<" ";
    }
    cout<<endl;
  }
}*/

void BFS(int M[][10], int size_x, int size_y, int start_x, int start_y)
{
    bool visited[size_x][size_y];
    int x = start_x, y = start_y;
    queue<QItem> Q;
    Q.push(QItem(start_x, start_y));
    visited[x][y] = true;
    while(!Q.empty())
    {
      QItem temp = Q.front();
      Q.pop();
      cout<<M[temp.row][temp.col]<<" ";
      if (temp.row > 0 && visited[temp.row][temp.col] == false)
      {
          Q.push(QItem(temp.row-1 , temp.col));
          visited[temp.row-1][temp.col] = true;
      }

      if (temp.row < size_x && visited[temp.row][temp.col] == false)
      {
          Q.push(QItem(temp.row+1 , temp.col));
          visited[temp.row+1][temp.col] = true;
      }

      if (temp.col > 0 && visited[temp.row][temp.col] == false)
      {
          Q.push(QItem(temp.row , temp.col-1));
          visited[temp.row-1][temp.col-1] = true;
      }

      if (temp.col < size_y && visited[temp.row][temp.col] == false)
      {
          Q.push(QItem(temp.row , temp.col+1));
          visited[temp.row][temp.col+1] = true;
      }
    }
}

int main()
{
  int size_x = 5;
  int size_y = 10;
  int start_x = 0;
  int start_y = 0;
  int M[size_x][size_y];
  //createMatrix(M, 5, 10);
  for ( int i = 0; i < size_x; ++i )
  {
    for ( int j = 0; j < size_y; ++j )
    {
      M[i][j] = rand()%100;
      cout<<M[i][j]<<" ";
    }
    cout<<endl;
  }
  BFS(M, 5, 10, start_x, start_y);
  return 0;
}
