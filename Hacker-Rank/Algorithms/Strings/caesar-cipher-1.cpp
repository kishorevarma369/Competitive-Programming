#include <bits/stdc++.h>

using namespace std;

string caesarCipher(string s, int k)
{
    k=k%26;
    int i,len=s.size();
    for(i=0;i<len;i++)
    {
      if(isalpha(s[i]))
      {
        if(isupper(s[i]))
        {
          //s[i]+=k;
          if(s[i]+k>'Z') s[i]=(s[i]+k-'A')%26+'A';
          else s[i]+=k;
        }
        else
        {

          if(s[i]+k>'z') s[i]=(s[i]+k-'a')%26+'a';
          else s[i]+=k;
        }
      }
    }
    return s;
}

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int k;
    cin >> k;
    string result = caesarCipher(s, k);
    cout << result << endl;
    return 0;
}
