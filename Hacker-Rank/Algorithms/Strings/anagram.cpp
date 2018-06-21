#include <bits/stdc++.h>

using namespace std;

int anagram(string s)
{
      if(s.size()&1) return -1;
      int a[26]={0},b[26]={0},count=0,i;
      int size=s.size()/2;
      for(i=0;i<size;i++) a[s[i]-'a']++;
      size=s.size();
      for(;i<size;i++)
      {
        b[s[i]-'a']++;
      }
      for(i=0;i<26;i++)
      {
        count+=abs(a[i]-b[i]);
        //cout<<char(i+'a')<<"="<<abs(a[i]-b[i])<<'\n';
      }
      return count/2;
}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        string s;
        cin >> s;
        int result = anagram(s);
        cout << result << endl;
    }
    return 0;
}
