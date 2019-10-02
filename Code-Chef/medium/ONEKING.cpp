#include<bits/stdc++.h>

using namespace std;

#define mymod 1000000007

#define fast_io() (cin.tie(NULL),ios_base::sync_with_stdio(false))

typedef unsigned long long int ull;
typedef long long int ll;


template<typename t>
t modulo_power(t x,t y,t mod=mymod)
{
    if(y<=0) return 1;
    if(y==1) return x;
    t z=modulo_power(x,y/2);
    if(y&1) return ((z*z)%mod*x)%mod;
    return (z*z)%mod;
}

void solve()
{
    int n,x,y;
    cin>>n;
    vector<int> v(2008,-1);
    for(int i=0;i<n;i++)
    {
        cin>>x>>y;
        
    }
}

int main()
{
    fast_io();
    ull t;
    cin>>t;
    while(t--) solve();
    return 0;
}