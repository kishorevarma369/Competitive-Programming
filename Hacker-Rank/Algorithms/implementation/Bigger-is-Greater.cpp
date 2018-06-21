#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
  int n;
  cin>>n;
  while(n--)
  {
    string s;
    cin>>s;
    auto k=next_permutation(s.begin(),s.end());
    if(k==0) cout<<"no answer\n";
    else cout<<s<<'\n';
  }
  return 0;
}
