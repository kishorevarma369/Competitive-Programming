/*
Cleaning Up
*/

#include<bits/stdc++.h>
using namespace std;

void fun()
{
  int m,n,k,i;
  cin>>m>>n;
  vector<int> v(m+1,0);
  for(i=0;i<n;i++)
  {
    cin>>k;
    v[k]=1;
  }
  k=0;
  for(i=1;i<=m;i++)
  {
    if(v[i]==0)
    {
      if(k==0)
      {
        v[i]=1;
        k=1;
        cout<<i<<' ';
      }
      else k=0;
    }
  }
  cout<<'\n';
  for(i=2;i<=m;i++) if(!v[i]) cout<<i<<' ';
  cout<<'\n';
}

int main(int argc, char const *argv[])
{
  int n;
  cin>>n;
  while(n--)
  {
    fun();
  }
  return 0;
}
