#include<bits/stdc++.h>

using namespace std;

#define uplim 100005
#define mod 1000000007
#define multiply(val1,val2) (((val1%mod)*(val2%mod))%mod)
#define add(val1,val2) ((val1%mod+val2%mod)%mod)
#define substract(val1,val2) (((val1%mod)-(val2%mod)+mod)%mod)

typedef long long int ll;

vector<ll> v(100001);

void solve()
{
    ll n,m,prev=0,two_power=1,power;
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>v[i];
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++)
    {
        prev=prev*2+v[i];
        v[i]=prev/two_power+1;
        two_power*=2;
    }
    // 5 6 4 3 2 9 6
    // while(m--)
    // {
    //     cin>>power;
    //     cout<<ll(upper_bound(v.begin(),v.end(),power)-v.begin())<<'\n';
    // }
    for(auto &val:v) cout<<val<<' ';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--) solve();
    return 0;
}