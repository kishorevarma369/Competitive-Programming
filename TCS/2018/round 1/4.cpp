#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define mod 1000000007

ll sum2(ll n)
{
    return ((n*(n+1))%mod)/2;
}

ll sum1(ll n)
{
    return ((n*(n+1))/2)%mod;
}


int main(int argc, char const *argv[])
{
    ll c=0,k;
    
    for(ll i=1;i<=1000000;i++)
    {
        if(sum1(i)!=sum2(i))
        {
            k=(i*(i+1));
            cout<<i<<'\n';
            //cout<<k<<'\n';
            //cout<<(k/2)%mod<<' '<<(k%mod)/2<<'\n';
            system("pause");
        }
    }
    return 0;
}
