#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll gcd,v;
        cin>>gcd;
        for(ll i = 1; i < n; i++)
        {
            cin>>v;
            gcd=__gcd(gcd,v);
        }
        if(gcd==1) cout<<n<<'\n';
        else cout<<-1<<'\n';
    }
    return 0;
}
