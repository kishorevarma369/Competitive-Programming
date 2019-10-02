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
    ll val=1,res0=0,res1=0,ans=0;
    for(int i=0;i<ms;i++)
    {
        if(a[i]=='0') res0=(res0+val)%mymod;
        else res1=(res1+val)%mymod;
        if(b[i]=='1') ans=(ans+res0)%mymod;
        else ans=(ans+res1)%mymod;
        val=(val*2)%mymod;
    }
    cout<<res0<<' '<<res1<<' '<<ans<<'\n';
    int to_perform=(314160-int(ms))%mymod;
    ans=(ans+(res1*to_perform)%mymod)%mymod;
    cout<<ans<<'\n';
    return 0;
}