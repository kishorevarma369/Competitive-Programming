#include<bits/stdc++.h>

using namespace std;

#define mymod 1000000007
typedef long long int ll;

int main()
{
    string a,b,c;
    cin>>a>>b;
    auto ms=max(a.size(),b.size());
    a=string(ms-a.size(),'0')+a;
    b=string(ms-b.size(),'0')+b;
    ll val=1,res0=0,res1=0,ans=0,bval=0,aval=0,ares=0,bres=0;
    for(int i=0;i<ms;i++)
    {
        if(a[i]=='0') res0=(res0+val)%mymod;
        else res1=(res1+val)%mymod;
        if(b[i]=='1') ans=(ans+res0)%mymod;
        else ans=(ans+res1)%mymod;
        val=(val*2)%mymod;
    }
    for(int i=0;i<ms;i++)
    {
        bval=(bval*2+b[i]-'0')%mymod;
        aval=(aval*2+a[i]-'0')%mymod;
        bres=(bres+bval)%mymod;
        //ares=(ares+aval)%mymod;
    }
    for(int i=0;i<ms;i++)
    {
        bres=(bres*2)%mymod;
        bval=(bval*2)%mymod;
    }
    ans=(ans+bres)%mymod;
    ans=(ans+bval)%mymod;
    for(int i=ms;i<314160;i++)
    {
        bval=(bval*2)%mymod;
        ans=(ans+bval)%mymod;
    }
    //cout<<res0<<' '<<res1<<' '<<ans<<'\n';
    int to_perform=(314160-int(ms))%mymod;
    ans=(ans+(aval*to_perform)%mymod)%mymod;
    cout<<ans<<'\n';
    return 0;
}