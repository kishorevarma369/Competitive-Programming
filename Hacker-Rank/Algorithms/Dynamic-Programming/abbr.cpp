#include <bits/stdc++.h>

using namespace std;

string abbreviation(string a, string b) {
    int as=a.size(),bs=b.size();
    vector<vector<int>> dp(as+1,vector<int>(bs+1));
    dp[0][0]=1;
    for(int i=0;i<as;i++) if(islower(a[i])) dp[i+1][0]=dp[i][0];
    for(int i=0;i<as;i++)
    {
        for(int j=0;j<=i&&j<bs;j++)
        {
            if(islower(a[i]))
            {
                if(toupper(a[i])==b[j])
                {
                    dp[i+1][j+1]=max(dp[i][j+1],dp[i][j]);
                }
                else
                {
                    dp[i+1][j+1]=dp[i][j+1];
                }
                
            }
            else
            {
                if(a[i]==b[j]) dp[i+1][j+1]=dp[i][j];
            }
        }
    }
    // for(auto &row:dp)
    // {
    //     for(auto &col:row) cout<<col<<' ';
    //     cout<<'\n';
    // }
    string str;
    if(dp[as][bs]) str= "YES";
    else str= "NO";
    return str;
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

/*
#include <bits/stdc++.h>

using namespace std;

 // we fail 3 test cases because
 // aAbCcAD
 // AABCD
 // but we can't ignore 'A' in first string as it must be included compulsorily
 // need to find a way to solve it. 

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
*/

/*

previous attempt


#include <bits/stdc++.h>

using namespace std;

string abbreviation(string a, string b) {
    int m=a.size(),n=b.size();
    vector<vector<int>> v(n+1,vector<int>(m+1,0));
    a='0'+a;
    b='0'+b;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++){
            if(b[i]==toupper(a[j])) v[i][j]=v[i-1][j-1]+1;
            else v[i][j]=max(v[i-1][j],v[i][j-1]);
        } 
    }
    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=1;j<=m;j++) cout<<v[i][j]<<' ';
    //     cout<<'\n';
    // }
    if(v[n][m]==n)
    {
        vector<bool> t(a.size(),false);
        int i=n,j=m;
        while(i>0&&j>0)
        {
            if(v[i][j-1]==v[i-1][j])
            {
                t[j]=true;
                i--,j--;
            }
            else if(v[i][j-1]==v[i][j]) j--;
            else i--;
        }
        for(int i=1;i<a.size();i++)
        {
            if(!t[i]&&isupper(a[i])) goto finassss;
        }
        return "YES";
    } 
    finassss:
    return "NO";
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


*/