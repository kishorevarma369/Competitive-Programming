#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;
#define size 100001

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<ll> a(n),b(n);
    for(auto &val:a) cin>>val;
    for(auto &val:b) cin>>val;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    ll ans=0;
    for(int i=0;i<n;i++)
    {
        ans+=abs(a[i]-b[i]);
    }
    cout<<ans<<'\n';
    return 0;

}