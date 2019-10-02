#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,t,p,q;
    ll a[1001]={0};
    cin>>n>>t;
    for(p=0;p<n;p++)
    {
        cin>>q;
        a[q]++;
    }
    for(p=1;p<1001;p++)
    {
        a[p]+=a[p-1];
    }
    while(t>1)
    {
        cin>>p>>q;
        if(p>0) cout<<a[q]-a[p-1]<<'\n';
        else cout<<a[q]<<'\n';
        t--;
    }
    if(t==1)
    {
        cin>>p>>q;
        if(p>0) cout<<a[q]-a[p-1];
        else cout<<a[q];
    }
    return 0;
}