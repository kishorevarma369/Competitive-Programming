#include<bits/stdc++.h>

using namespace std;

#define uplim 1000005
#define mod 1000000007
typedef unsigned long long int ll;
int charset[uplim][26];
vector<int> poslis[26];

string s;
ll ans;

void pre()
{
    cin>>s;
    for(int i=0;i<s.size();i++){
        charset[i+1][s[i]-'a']++;
        poslis[s[i]-'a'].push_back(i+1);
    }
    for(int i=2;i<=s.size();i++)
    {
        for(int j=0;j<26;j++) charset[i][j]+=charset[i-1][j];
    }
    // for(int i=0;i<26;i++)
    // {
    //     if(poslis[i].size())
    //     {
    //         cout<<char(i+'a')<<' ';
    //         for(auto &elm:poslis[i]) cout<<elm<<' ';
    //         cout<<'\n';
    //     }
    // }
    // for(int i=0;i<=s.size();i++)
    // {
    //     for(int j=0;j<26;j++) cout<<charset[i][j]<<' ';
    //     cout<<'\n';
    // }
}

int main()
{
    pre();
    ans=0;
    ll tmp;
    for(int i=0;i<26;i++)
    {
        auto &mlist=poslis[i];
        for(int j=0;j<mlist.size();j++)
        {
            for(int k=j+1;k<mlist.size();k++)
            {
                for(int l=0;l<26;l++)
                {
                    // cout<<charset[mlist[k-1]][l]<<' '<<charset[mlist[j]][l]<<'\n';
                    tmp=charset[mlist[k]-1][l]-charset[mlist[j]][l];
                    ans=(ans+((tmp*(tmp-1))/2)%mod)%mod;
                }
            }
        }
    }
    cout<<ans<<'\n';
    return 0;
}