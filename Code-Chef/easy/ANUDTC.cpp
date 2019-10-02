#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        if(360%n==0) cout<<"y ";
        else cout<<"n ";
        if(n>360) cout<<"n ";
        else cout<<"y ";
        if(n>=360) cout<<"n\n";
        else cout<<"y\n";
    }
    return 0;

}