#include <bits/stdc++.h>

using namespace std;

int makingAnagrams(string s1, string s2)
{
    int size=s1.size(),i,count=0;
    char a[26]={0};
    for(i=0;i<size;i++) a[s1[i]-'a']++;
    size=s2.size();
    for(i=0;i<size;i++) a[s2[i]-'a']--;
    for(i=0;i<26;i++)
    {
      if(a[i]<0) count+=a[i]*-1;
      else count+=a[i];
    }
    return count;
}

int main() {
    string s1;
    cin >> s1;
    string s2;
    cin >> s2;
    int result = makingAnagrams(s1, s2);
    cout << result << endl;
    return 0;
}
