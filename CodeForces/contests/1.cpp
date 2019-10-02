#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long int ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,s;
    cin>>n>>s;
    ll val=s/n;
    if(s%n!=0) val++;
    cout<<val<<'\n';
    return 0;
}