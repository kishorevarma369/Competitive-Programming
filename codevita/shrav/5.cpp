#include<bits/stdc++.h>

using namespace std;

vector<int> values;
int ans[10000];
int main()
{
  int n,val;
  cin>>n;
  values.reserve(n);
  for(int i=0;i<n;i++) cin>>val,values.push_back(val);
  cin>>val;
  ans[0]=1;
  for(auto value:values)
  {
    for(int i=value;i<=10000;i++)
    {
      ans[i]+=ans[i-value];
    }
  }
  cout<<ans[val]<<'\n';
  return 0; 
}