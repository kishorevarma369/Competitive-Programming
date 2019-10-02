#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t,n,a,b,c;
    cin>>t;
    while(t--)
    {
        cin>>n;
        vector<ll> v(3);
        for(int i=0;i<3;i++) cin>>v[i];
        // sort(v.begin(),v.end());
        ll i=0,pos=INT64_MIN,dist=INT64_MAX;
        for(;i<3;i++) if(abs(n-v[i])<dist) dist=abs(n-v[i]),pos=v[i];
        cout<<pos<<'\n';
    }    
    return 0;
}