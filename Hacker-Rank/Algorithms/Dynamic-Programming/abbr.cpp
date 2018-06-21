#include <bits/stdc++.h>

using namespace std;
/*
  we fail 3 test cases because
  aAbCcAD
  AABCD

  but we can't ignore 'A' in first string as it must be included compulsorily
  need to find a way to solve it. 

*/
string abbreviation(string a, string b) {
    int as[26]={0},ac[26]={0},bl[26]={0},i;
    if(a.size()<b.size())
    {
        return string("NO");
    }
    for(i=0;i<a.size()&&i<b.size();i++)
    {
        if(islower(a[i])) as[a[i]-'a']++;
        else ac[a[i]-'A']++;
        bl[b[i]-'A']++;
    }
    for(;i<a.size();i++)
    {
        if(islower(a[i])) as[a[i]-'a']++;
        else ac[a[i]-'A']++;
    }
    for(;i<b.size();i++)
    {
        bl[b[i]-'A']++;
    }
    for(i=0;i<26;i++)
    {
        if(ac[i]>bl[i]) return string("NO");
        else
        {
            if(ac[i]!=bl[i])
            {
                if(as[i]<(bl[i]-ac[i])) return string("NO");
                //else as[i]=as[i]-bl[i]+ac[i];
            }
            else
            {
                as[i]=0;
            }
        }
    }
    for(i=0;i<a.size();i++)
    {
        if(islower(a[i]))
        {
            if(as[a[i]-'a']==0) a[i]=' ';
        }
    }
    string c;
    for(i=0;i<a.size();i++)
    {
      if(a[i]!=' ')
      {
        if(islower(a[i])) c.push_back(a[i]-'a'+'A');
        else c.push_back(a[i]);
      }
    }
    int j=0;
    bool found;
    for(i=0;i<b.size()&&j<c.size();i++)
    {
      found=false;
      for(;j<c.size();j++) if(c[j]==b[i]){ found=true;j++;break;}
      if(!found) break;
    }
    if(i==b.size()) return string("YES");
    else return string("NO");
}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        string a;
        cin >> a;
        string b;
        cin >> b;
        string result = abbreviation(a, b);
        cout << result << endl;
    }
    return 0;
}
