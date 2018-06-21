#include <bits/stdc++.h>

using namespace std;

map<int,char> err_in_pallindrome(string s)
{
  int i=0,j=s.size()-1;
  map<int,char> my;
  while(i<j)
  {
    if(s[i]!=s[j]) my[i]=max(s[i],s[j]);
    i++;
    j--;
  }
  return my;
}

string richieRich(string s, int n, int k)
{
    auto mymap=err_in_pallindrome(s);
    auto size=mymap.size();
    auto ssize=n-1;
    if(k==0)
    {
      if(size!=0) return string("-1");
      return s;
    }
    if(size==0)
    {
      size=n/2;
      if(k&1)
      {
        s[size]='9';
      }
      auto l=(k>>1),i=0;
      while(l>0&&i<size)
      {
        if(s[i]!='9'&&s[ssize-i]!='9') l--;
        s[i]=s[ssize-i]='9';
        i++;
      }
    }
    else if(size>k) return string("-1");
    else if(size==k)
    {
      for(auto i:mymap)
      {
        s[i.first]=s[ssize-i.first]=i.second;
      }
    }
    else
    {
      auto it=mymap.begin();
      auto avail=k-size;
      while(avail>0&&it!=mymap.end())
      {
        s[it->first]=s[ssize-it->first]='9';
        if(it->second!='9') avail--;
        it++;
      }
      auto i=0,msize=(n)/2;
      while(avail>0&&i<msize)
      {
        if(s[i]!='9') avail-=2;
        s[i]=s[ssize-i]='9';
        i++;
      }
      while(it!=mymap.end())
      {
        s[it->first]=s[ssize-it->first]=it->second;
        it++;
      }
      if(n&1) if(avail) s[ssize/2]='9';
    }
    return s;
}

int main() {
    int n;
    cin >> n;
    int k;
    cin >> k;
    string s;
    cin >> s;
    string result = richieRich(s, n, k);
    cout << result << endl;
    return 0;
}
