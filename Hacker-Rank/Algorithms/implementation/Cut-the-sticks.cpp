#include<bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
  int n,i,j,count=0,k=0,ul,prev;
  cin>>n;
  map<int,int> s;
  for(i=0;i<n;i++)
  {
    cin>>j;
    if(s.count(j)) s[j]+=1;
    else s.insert(pair<int,int>(j,1));
  }
  k=s.size();
  prev=0;
  j=1;
  vector<int> v(k+1,0);
  for(auto i:s)
  {
    v[j]=v[j-1]+i.second;
    j++;
  }
  auto l=v[j-1];
  for(i=0;i<k;i++)
  {
    cout<<l-v[i]<<'\n';
  }
  return 0;
}
