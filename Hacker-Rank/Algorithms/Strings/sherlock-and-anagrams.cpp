#include<bits/stdc++.h>
using namespace std;

void fun()
{
  string s;
  cin>>s;
  int size=s.size(),k,i,count=0,j;
  map<vector<int>,int> amap;
  vector<vector<int>> ind;
  vector<int> v(26,0);
  for(i=0;i<size;i++)
  {
    v[s[i]-'a']++;
    ind.push_back(v);
    amap[v]++;
  }
  for(i=1;i<size;i++)
  {
    k=s[i-1]-'a';
    for(j=i;j<size;j++)
    {
      ind[j][k]-=1;
      amap[ind[j]]++;
    }
  }
  for(auto t:amap)
  {
    if(t.second>1) count+=(t.second*(t.second-1))/2;
  }
  cout<<count<<'\n';
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
