#include<bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
  int a[26]={0},i=0;
  char ch;
  while((ch=getchar())!=EOF)
  {
    if(ch==' ')
    {
      i++;
      continue;
    }
    if(isupper(ch)) a[ch-'A']+=1;
    else a[ch-'a']+=1;
    i++;
  }
  for(i=0;i<26;i++) if(!a[i]) break;
  if(i==26) cout<<"pangram";
  else cout<<"not pangram";
  return 0;
}
