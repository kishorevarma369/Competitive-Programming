#include<bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
  int n,t,p;
  cin>>n;
  while(n--)
  {
    set<int> s;
    cin>>t;
    while(t--)
    {
      cin>>p;
      s.insert(p);
    }
    cout<<s.size()<<'\n';
  }
  return 0;
}
