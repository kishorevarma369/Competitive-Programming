#include <bits/stdc++.h>

using namespace std;

int visited[11][11],m,n;

int fun(int i,int j,vector < vector<int> > &matrix)
{
  if(i<0||i==m||j==n||j<0||visited[i][j]==1||matrix[i][j]==0) return 0;
  visited[i][j]=1;
  return 1+fun(i+1,j,matrix)+fun(i-1,j-1,matrix)+fun(i+1,j+1,matrix)+ fun(i-1,j+1,matrix)+fun(i+1,j-1,matrix)+fun(i,j+1,matrix)+fun(i,j-1,matrix)+fun(i-1,j,matrix);
}

int connectedCell(vector < vector<int> > &matrix)
{
    int ma=0,co,i,j;
    for(i=0;i<m;i++)
    {
      for(j=0;j<n;j++)
      {
        if(!visited[i][j]&&matrix[i][j]!=0)
        {
          co=fun(i,j,matrix);
          if(ma<co) ma=co;
        }
      }
    }
    return ma;
}

int main() {
    cin >> m >> n;
    vector< vector<int> > matrix(m,vector<int>(n));
    for(int matrix_i = 0;matrix_i < m;matrix_i++){
       for(int matrix_j = 0;matrix_j < n;matrix_j++){
          cin >> matrix[matrix_i][matrix_j];
       }
    }
    int result = connectedCell(matrix);
    cout << result << endl;
    return 0;
}
