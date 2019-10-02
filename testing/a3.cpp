#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n,m;
  cin>>n>>m;
  vector<int> v(n);
  for(auto &val:v) cin>>val;
  sort(v.begin(),v.end());
  int val;
  for(int i=0;i<m;i++)
  {
    cin>>val;
    cout<<(upper_bound(v.begin(),v.end(),val)-v.begin())<<' ';
  }
  return 0;
}