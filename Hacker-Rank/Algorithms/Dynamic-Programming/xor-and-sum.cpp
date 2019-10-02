#include<bits/stdc++.h>

using namespace std;

#define mymod 1000000007
typedef long long int ll;
int main()
{
    string a,b,c;
    cin>>a>>b;
    reverse(a.begin(),a.end());
    c=a;
    reverse(b.begin(),b.end());
    auto ms=max(a.size(),b.size());
    a.resize(ms,'0');
    b.resize(ms,'0');
    ll val=1,res=0,ans=0;
    for(auto &ch:a)
    {
        if(ch=='0') ch='1';
        else ch='0';
    } 
    for(int i=0;i<ms;i++)
    {
        if(a[i]=='1') res=(res+val)%mymod;
        if(b[i]=='1') ans=(ans+res)%mymod;
        val=(val*2)%mymod;
    }
    int to_process=(314159-ms)%mymod;
    res=0;
    val=1;
    for(auto &ch:c)
    {
        if(ch=='1') res=(res+val)%mymod;
        val=(val*2)%mymod;
    }
    ans=(ans+(val*to_process)%mymod)%mymod;
    cout<<ans<<'\n';
    return 0;
}