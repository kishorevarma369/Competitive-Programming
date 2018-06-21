#include <bits/stdc++.h>

using namespace std;

int indexi,indexj;

int ispallindrome(char *s,int size)
{
  int i=0,j=size-1;
  while(i<j)
  {
    if(s[i]!=s[j])
    {
      indexi=i;
      indexj=j;
      break;
    }
    i++;
    j--;
  }
  if(i<j) return 0;
  return 1;
}

void strnacopy(char *d,char *s,int pos, int size)
{
  int i=0,j=0;
  while(j<pos) d[i++]=s[j++];
  j++;
  while(j<size) d[i++]=s[j++];
  d[i]=0;
}

int palindromeIndex(char * s)
{
      int size=strlen(s);
      int i,j;
      char temp[100005];
      if(!ispallindrome(s,size))
      {
        i=indexi;
        j=indexj;
        strnacopy(temp,s,i,size);
        if(ispallindrome(temp,size-1)) return i;
        strnacopy(temp,s,j,size);
        if(ispallindrome(temp,size-1)) return j;
      }
      return -1;
}

int main() {
    int q;
    cin >> q;
    char s[100006];
    for(int a0 = 0; a0 < q; a0++){
        cin >> s;
        int result = palindromeIndex(s);
        cout << result << endl;
    }
    return 0;
}
