/*
Ciel and A-B Problem 
*/

#include<bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
  int a,b;
  cin>>a>>b;
  string s=to_string(abs(a-b));
  if(s[0]=='1') s[0]='2';
  else s[0]='1';
  cout<<s<<'\n';
  return 0;
}
