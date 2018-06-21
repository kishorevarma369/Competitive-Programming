//good
#include<bits/stdc++.h>

using namespace std;

string isValid(string s)
{
      map<char,int> index;
      map<int,int> iofi;
      string k;
      for(int i=0;i<s.size();i++)
      {
        index[s[i]]++;
      }
      for(auto i:index)
      {
        iofi[i.second]++;
      }
      for(auto i:iofi)
      {
        cout<<i.first<<' '<<i.second<<'\n';
      }
      if(iofi.size()==1) k="YES";
      else if(iofi.size()>2) k="NO";
      else
      {
        int min=INT_MAX,minel,other=0;
        for(auto l:iofi)
        {
          if(l.second<min)
          {
            other^=l.first;
            min=l.second;
            minel=l.first;
          }
        }
        other^=minel;
        if(min==1&&(minel-1==other||minel-1==0)) k="YES";
        else k="NO";
      }
      return k;
}

int main() {
    string s;
    cin >> s;
    string result = isValid(s);
    cout << result << endl;
    return 0;
}
