#include<bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
  int m,n,i,val;
  map<int,int> mymap;
  cin>>m;
  for(i=0;i<m;i++)
  {
    cin>>val;
    mymap[val]++;
  }
  cin>>n;
  for(i=0;i<n;i++)
  {
    cin>>val;
    auto it=mymap.find(val);
    if(it==mymap.end())
    {
      mymap[val]-=1;
    }
    else
    {
      (it->second)--;
      if(it->second==0) mymap.erase(it);
    }
  }
  for(auto &j:mymap)
  {
    cout<<j.first<<' ';
  }
  return 0;
}
