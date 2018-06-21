/*

      Question :-

          https://www.hackerrank.com/challenges/matrix-rotation-algo

      Idea:
          go through the entire layer and push elements on to vector and then use
          modulo principle to get rotated matrix

      ***************************************************************************
      --------------------written by KISHORE VARMA-------------------------------
      ***************************************************************************
*/

#include<iostream>
#include<vector>
#define max(m,n) (m>n?m:n)
#define min(m,n) (m>n?n:m)
using namespace std;
int main(int argc, char const *argv[])
{
  int m,n,k,i,j,rot,l,lim;
  cin>>m>>n>>rot;
  k=min(m,n);
  k/=2;
  int a[m][n];
  for (i = 0; i < m; i++) for (j = 0; j < n; j++) cin>>a[i][j];
  vector<int> v[k];
  for (int loop = 0; loop <k; loop++)
  {
    i=j=loop;
    for (;j<n-loop;j++) v[loop].push_back(a[i][j]);
    j--;i++;
    for (;i<m-loop;i++) v[loop].push_back(a[i][j]);
    i--;j--;
    for (;j>=loop;j--) v[loop].push_back(a[i][j]);
    j++;i--;
    for (;i>loop;i--) v[loop].push_back(a[i][j]);
  }

  for (int loop = 0; loop <k; loop++)
  {
    i=j=loop;
    lim=v[loop].size();
    l=rot%lim;
    for (;j<n-loop;j++)
    {
      if(l==lim) l=0;
      a[i][j]=v[loop][l++];
    }
    j--;i++;
    for (;i<m-loop;i++)
    {
      if(l==lim) l=0;
      a[i][j]=v[loop][l++];
    }
    i--;j--;
    for (;j>=loop;j--)
    {
      if(l==lim) l=0;
      a[i][j]=v[loop][l++];
    }
    j++;i--;
    for (;i>loop;i--)
    {
      if(l==lim) l=0;
      a[i][j]=v[loop][l++];
    }
  }
  for (i = 0; i < m; i++)
  {
    for (j = 0; j < n; j++)
    {
      cout<<a[i][j]<<' ';
    }
    cout<<'\n';
  }
  return 0;
}
