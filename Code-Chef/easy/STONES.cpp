#include<bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
  int n,c=0;
  char ch;
  cin>>n;
  string a,b;
  while(n--)
  {
    cin>>a>>b;
    map<char,int> m1,m2;
    for(auto i:a) m1[i]++;
    for(auto i:b) m2[i]++;
    c=0;
    for(auto &i:m1)
    {
      auto p=m2.find(i.first);
      if(p!=m2.end()) c+=p->second;
    }
    cout<<c<<'\n';
  }
  return 0;
}
