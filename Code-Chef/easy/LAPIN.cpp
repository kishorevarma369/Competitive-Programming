/*
Lapindromes
*/

#include<bits/stdc++.h>

using namespace std;

int fun(string s)
{
  int i,a[26]={0},len=s.size()/2;
  for(i=0;i<len;i++) a[s[i]-'a']++;
  if(s.size()%2) i++;
  for(;i<s.size();i++) a[s[i]-'a']--;
  for(i=0;i<26;i++) if(a[i]) return 0;
  return 1;
}

int main(int argc, char const *argv[])
{
  int n;
  cin>>n;
  string s;
  while(n--)
  {
    cin>>s;
    if(fun(s)) cout<<"YES\n";
    else cout<<"NO\n";
  }
  return 0;
}
