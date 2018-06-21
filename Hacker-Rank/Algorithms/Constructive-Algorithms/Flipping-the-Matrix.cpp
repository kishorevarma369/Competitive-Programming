#include <bits/stdc++.h>

using namespace std;

int maxul(int a , int b , int c , int d)
{
  int tmp=0;
  if(a>tmp) tmp=a;
  if(b>tmp) tmp=b;
  if(c>tmp) tmp=c;
  if(d>tmp) tmp=d;
  return tmp;
}

void fun()
{
  int n,no,i,j,sum=0,tmp;
  cin>>n;
  no=2*n;
  vector<vector<int>> v(no);
  for (i = 0; i < no; i++)
  {
    for (j = 0; j < no; j++)
    {
      cin>>tmp;
      v[i].push_back(tmp);
    }
  }
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      sum+=maxul(v[i][j],v[i][no-1-j],v[no-1-i][j],v[no-1-i][no-1-j]);
    }
  }
  cout<<sum<<'\n';
}

int main(int argc, char const *argv[])
{
  int q,i;
  cin>>q;
  for (i = 0; i < q; i++) fun();
  return 0;
}
