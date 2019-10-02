#include<bits/stdc++.h>

using namespace std;

#define mymod 1000000007
typedef long long int ll;
#define upbound 314159
int two_power[100001];

void pre()
{
    two_power[0]=1;
    for(int i=1;i<100001;i++) two_power[i]=(two_power[i-1]*2)%mymod;
}

int main()
{
    pre();
    string a,b,c;
    cin>>a>>b;
    auto ms=max(a.size(),b.size());
    a=string(ms-a.size(),'0')+a;
    b=string(ms-b.size(),'0')+b;
    ll val=1,res0=0,res1=0,ans=0,bval=0,aval=0,ares=0,bres=0;
    for(int i=0;i<ms;i++)
    {
        if(a[i]=='0') res0=(res0+two_power[ms-1-i])%mymod;
        else res1=(res1+two_power[ms-1-i])%mymod;
        if(b[i]=='1') ans=(ans+res0)%mymod;
        else ans=(ans+res1)%mymod;
        bval=(bval*2+b[i]-'0')%mymod;
        aval=(aval*2+a[ms-1-i]-'0')%mymod;
        ares=(ares+aval)%mymod;
        bres=(bres+bval)%mymod;
    }
    for(int i=0;i<ms;i++)
    {
        bres=(bres*2)%mymod;
        bval=(bval*2)%mymod;
    }
    ans=(ans+ares)%mymod;
    ans=(ans+bres)%mymod;
    //ans=(ans+bval)%mymod;
    for(int i=ms;i<upbound;i++)
    {
        bval=(bval*2)%mymod;
        ans=(ans+bval)%mymod;
    }
    //cout<<res0<<' '<<res1<<' '<<ans<<'\n';
    int to_perform=(upbound-int(ms)-1)%mymod;
    ans=(ans+(aval*to_perform)%mymod)%mymod;
    cout<<ans<<'\n';
    return 0;
}