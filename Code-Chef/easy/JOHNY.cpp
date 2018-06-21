/*
Uncle Johny 
*/
#include<bits/stdc++.h>

using namespace std;

void fun()
{
  int n,i,t;
  cin>>n;
  vector<int> v(n);
  for(i=0;i<n;i++) cin>>v[i];
  cin>>t;
  t=v[t-1];
  sort(v.begin(),v.end());
  for(i=0;i<n;i++) if(v[i]==t) break;
  cout<<i+1<<'\n';
}

int main()
{
  int n;
  cin>>n;
  while(n--) fun();
  return 0;
}
