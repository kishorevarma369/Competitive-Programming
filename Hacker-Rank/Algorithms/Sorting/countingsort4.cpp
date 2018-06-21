#include<bits/stdc++.h>

using namespace std;

typedef struct
{
  vector<string> v;
  int co;
  mystruct()
  {
    co=0;
  }
}mystruct;

int main(int argc, char const *argv[])
{
  map<int,mystruct> v;
  int n,i,k;
  cin>>n;
  k=n/2;
  string s;
  while(n--)
  {
    cin>>i>>s;
    if(n>=k) v[i].co++;
    else v[i].v.push_back(s);
  }
  for(auto &i:v)
  {
    for(auto j=0;j<i.second.co;j++) cout<<"- ";
    for(auto &j:i.second.v) cout<<j<<' ';
  }
  return 0;
}
