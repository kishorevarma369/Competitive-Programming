#include<bits/stdc++.h>
using namespace std;


int main()
{
    string s;
    cin >> s;
    set<int> myset;
    int i,j,k,t;
    for(i=0;i<s.size();)
    {
      k=s[i]-'a'+1;
      myset.insert(k);
      t=k;
      for(j=i+1;j<s.size();j++)
      {
        if(s[j]==s[i])
        {
          t+=k;
          myset.insert(t);
        }
        else break;
      }
      i=j;
    }
    int n;
    cin >> n;
    for(int a0 = 0; a0 < n; a0++)
    {
        int x;
        cin >> x;
        auto a=myset.find(x);
        if(a==myset.end()) cout<<"No\n";
        else cout<<"Yes\n";
    }
    return 0;
}
