#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define mod 1000000007

void solve()
{ 
    ll n,k,x,sum,val=1,prevsum=0;
    cin>>n>>k>>x;
    sum=k-1;
    for(int l=3;l<=n;l++)
    {
      val=(mod+sum-val)%mod;
      prevsum=sum;
      if(l&1) sum=(k*val+1)%mod;
      else sum=(k*val-1)%mod;
    }
    if(x==1)
    {
        if(n&1) val++;
        else val--;
        val=(val+mod)%mod;
    }
    cout<<val<<'\n';
}

int main() {
    solve();
    return 0;
}
