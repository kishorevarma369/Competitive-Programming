#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long int ll;

vector<ll> finallist;

#define uplim 10000000000ll


int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    ll t,n,val,k;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        vector<ll> v(n);
        for(int i=0;i<n;i++) cin>>v[i];
        ll msum=0,i,mmax=0;
        for(i=0;i<k;i++) msum+=v[i];
        mmax=msum;
        for(;i<n;i++){
            msum+=v[i]-v[i-k];
            if(mmax<msum) msum=mmax; 
        }
        cout<<mmax<<'\n';
    }
    return 0;
}