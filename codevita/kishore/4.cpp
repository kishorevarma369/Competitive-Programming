#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;
int f[1000005];
#define mod 1000000007
void pre()
{
    f[0]=f[1]=1;
}

int main()
{
    pre();
    int n;
    cin>>n;
    for(int i=2;i<=n;i++) f[i]=(f[i-1]+f[i-2])%mod;
    ll ans=f[n],k=n-3;
    for(ll i=0;i<=k;i++)
    {
        ans=(ans+((ll)f[i]*f[k-i])%mod)%mod;
    }
    cout<<ans<<'\n';
    return 0;
}