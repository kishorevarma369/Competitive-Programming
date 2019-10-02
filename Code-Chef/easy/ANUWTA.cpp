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
        cout<<n+(n*(n+1))/2<<'\n';
    }
    return 0;
}
