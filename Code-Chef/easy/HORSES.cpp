/*
Racing Horses
*/

#include<bits/stdc++.h>

using namespace std;

void fun()
{
  int n,diff=INT_MAX;
  cin>>n;
  std::vector<int> v(n);
  for(int i=0;i<n;i++) cin>>v[i];
  sort(v.begin(),v.end());
  for(int i=1;i<n;i++)
  {
    if(diff>v[i]-v[i-1]) diff=v[i]-v[i-1];
  }
  cout<<diff<<'\n';
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
