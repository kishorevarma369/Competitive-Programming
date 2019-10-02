#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

vector<ll> primes;
vector<ll> finallist;

#define uplim 10000000000

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
    finallist.push_back(1);
    for(auto prime:primes)
    {
        set<ll> tlist;
        ll k=prime*prime;
        for(ll i=k;i*i<=uplim;i*=k)
        {
            for(auto &item:finallist)
            {
                if(item*i<=uplim) tlist.insert(item*i);
                else break;
            }
        }
        finallist.emplace_back(tlist.begin(),tlist.end());
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
        auto it=upper_bound(finallist.begin(),finallist.end(),n);
        cout<<it-finallist.begin()<<'\n';
    }
    cout<<"Done\n";
    return 0;
}