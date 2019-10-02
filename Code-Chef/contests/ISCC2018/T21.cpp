#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll val=0,ans;
        string s;
        cin>>s;
        for(auto &i:s) val+=i-'0';
        ans=val%3;
        val=0;
        cin>>s;
        for(auto &i:s) val+=i-'0';
        ans=(ans*val%3)%3;
        cout<<ans<<'\n';
    }
    return 0;
}