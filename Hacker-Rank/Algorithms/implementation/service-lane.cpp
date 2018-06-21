#include<bits/stdc++.h>
using namespace std;

void fun(vector<int> &v,int i, int j)
{
  auto min=4;
  for(;i<=j;i++)
  {
    if(v[i]<min) min=v[i];
  }
  cout<<min<<'\n';
}

int main(int argc, char const *argv[])
{
  int n,t,i,j;
  cin>>n>>t;
  vector<int> v(n);
  for(i=0;i<n;i++) cin>>a[i];
  while(t--)
  {
    cin>>i>>j;
    fun(v,i,j);
  }
  return 0;
}
