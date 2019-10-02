#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long int ll;
#define mod 1000000007
ll inverse[1000001];
ll mypower(ll x,ll y)
{
    if(y==0) return 1;
    else if(y==1) return x%mod;
    ll t=mypower(x,y/2);
    if(y&1) return (((1ll*t*t)%mod)*x)%mod;
    return (1ll*t*t)%mod;
} 
  
void calcInverse(int n) 
{ 
    inverse[0]=inverse[1]=1;
    for(int i=2;i<=n;i++)
    {
        inverse[i]=(mypower(i,mod-2)*1ll*inverse[i-1])%mod;
        // cout<<"inv : "<<i<<" "<<inverse[i]<<'\n';
    }
} 
  

ll solve(int n)
{
    calcInverse(n);
    ll ans=1,finans=0,val=1,twopower=1;
    for(int i=2;i<=n;i++)
    {
        ans=(ans*i)%mod;
        val=(((twopower*inverse[i-2])%mod)*inverse[n-i])%mod;
        finans=(finans+val)%mod;
        twopower=(twopower*2)%mod;
    }
    return (finans*ans)%mod;
}


int main()
{
    ll n;
    cin>>n;
    ll ans=solve(n);
    // cout<<inverse[2]<<'\n';
    cout<<ans<<'\n';
    return 0;
}
