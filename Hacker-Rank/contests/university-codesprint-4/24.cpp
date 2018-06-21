#include <bits/stdc++.h>

using namespace std;

void fun(vector<long> v, int i ,int j,map<long,long> &mymap)
{
  long count=0,k;
  for(;i<=j;i++)
  {
    k=++mymap[v[i]];
    if(k==1) count++;
    else if(k==2) count--;
  }
  cout<<count<<'\n';
}

int main()
{
  ios_base::sync_with_stdio(0), cin.tie(0);
    int i,j,n,t;
    cin>>n;
    vector<long> v(n);
    for(i=0;i<n;i++) cin>>v[i];
    cin>>t;
    while(t--)
    {
      cin>>i>>j;
      i--,j--;
      fun(v,i,j);
    }
    return 0;
}
