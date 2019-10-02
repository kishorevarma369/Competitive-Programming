#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long int ll;

vector<ll> v;
ll a,b;

bool isvalid(ll val)
{
    ll k;
    while(val)
    {
        k=val%10;
        if(k==0||k==1||k==4||k==9) val/=10;
        else return false;
    }
    return true;
}

void gen()
{
    ll k;
    for(ll i=1;i<=100000;i++)
    {
        k=i*i;
        if(isvalid(k)) v.push_back(k);
    }
}

void calc()
{
    auto it1=lower_bound(v.begin(),v.end(),a);
    auto it2=upper_bound(v.begin(),v.end(),b);
    //while(it1<it2) cout<<*(it1++)<<'\n';
    cout<<int(it2-it1)<<'\n';
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    gen();
    ll t;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        calc();
    }
    return 0;
}
