#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

vector<ll> primes;

void pre()
{
    primes.push_back(2);
    bool isprime;
    for(ll i=3;i<=100000;i+=2)
    {
        isprime=true;
        for(auto prime:primes)
        {
            if(prime*prime>i) break;
            if((i%prime)==0){ isprime=false; break;}
        }
        if(isprime){
            primes.push_back(i);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    ll t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
    }
    cout<<"Done\n";
    return 0;
}