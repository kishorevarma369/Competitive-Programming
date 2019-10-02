#include<bits/stdc++.h>

using namespace std;

#define mymod 1000000007

typedef unsigned long long int ull;
typedef long long int ll;


template<typename t>
//x power y % mod y>=0
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
    ull n,k;
    cin>>n>>k;
    if(n<=k)
    {
        if(n<k) cout<<"0\n";
        else if(n==k) cout<<"1\n";
        return;
    }
    ull upto=min(k-1,n-k);
    ull ans=1;
    for(int i=0;i<upto;i++)
    {
        n--;
        ans=(ans*n)/(i+1);
    }
    cout<<ans<<'\n';
}
int main()
{
    ull t;
    cin>>t;
    while(t--) solve();
    // x1+x2+...xk = n-k
    // (n-k+k-1) c k-1 = (n-1)! / (k-1!*(n-k)!)
   
    return 0;
}