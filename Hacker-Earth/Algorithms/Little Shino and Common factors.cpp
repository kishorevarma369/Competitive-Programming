#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long int ll;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    ll a,b;
    cin>>a>>b;
    ll g=__gcd(a,b);
    ll div_by_two =0;
    while((g%2)==0)
    {
        g/=2;
        div_by_two++;
    }
    ll no_of_factors=2;
    ll k=sqrt(g);
    for(ll i=3;i<=k;i+=2)
    {
        if((g%i)==0) no_of_factors+=2; 
    }
    if((k*k)==g) no_of_factors--;
    no_of_factors=no_of_factors*(div_by_two+1);
    cout<<no_of_factors<<'\n';
    return 0;
}