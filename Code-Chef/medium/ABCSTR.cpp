#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;
void solve()
{
    string s;
    cin>>s;
    // vector<vector<ll>> v(3);
    // for(int i=0;i<3;i++) v[i].reserve(s.size()+1);
    map<pair<ll,ll>,ll> m;
    pair<ll,ll> mp={0,0};
    ll a=0,b=0,c=0;
    m[mp]=1;
    ll ans=0;
    for(auto &ch:s)
    {
        if(ch=='A') a++;
        else if(ch=='B') b++;
        else if(ch=='C') c++;
        else assert(false);
        mp={a-b,b-c};
        ans=ans+m[mp];
        m[mp]++;
    }
    cout<<ans<<'\n';
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t=1;
    while(t--)
    {
        solve();
    }
    return 0;
}