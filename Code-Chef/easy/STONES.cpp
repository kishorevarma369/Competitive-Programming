#include<bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
  int n,c=0,i;
  char ch;
  cin>>n;
  string a,b;
  while(n--)
  {
    int s[52]={0},s1[52]={0};
    cin>>a>>b;
    c=0;
    for(i=0;i<a.size();i++)
    {
      ch=a[i];
      if(islower(ch))
      {
        s[ch-'a']++;
      }
      else if(isupper(ch))
      {
        s[ch-'A'+26]++;
      }
    }
    for(i=0;i<b.size();i++)
    {
      ch=b[i];
      if(islower(ch))
      {
        s1[ch-'a']++;
      }
      else if(isupper(ch))
      {
        s1[ch-'A'+26]++;
      }
    }
    for(int i=0;i<52;i++)
    {
      c+=min(s[i],s1[i]);
    }
    cout<<c<<'\n';
  }
  return 0;
}
