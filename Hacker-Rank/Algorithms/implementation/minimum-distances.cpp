#include<bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
  int n,b,j=0,i,min=INT_MAX,locmin;
  cin>>n;
  vector<int> index(100000,-1);
  vector<vector<int>> v(n);
  for(i=0;i<n;i++)
  {
    cin>>b;
    if(index[b]==-1)
    {
      index[b]=j;
      v[j++].push_back(i);
    }
    else
    {
      v[index[b]].push_back(i);
    }
  }
  for(i=0;i<v.size();i++)
  {
    b=v[i].size();
    locmin=INT_MAX;
    if(b<2) continue;
    for(j=1;j<b;j++)
    {
      if(abs(v[i][j]-v[i][j-1])<locmin) locmin=abs(v[i][j]-v[i][j-1]);
    }
    if(min>locmin) min=locmin;
  }
  if(min==INT_MAX) cout<<"-1";
  else cout<<min;
  return 0;
}
