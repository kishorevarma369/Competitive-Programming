#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long int ll;

vector<ll> primes;
set<ll> finallist;
vector<ll> finlist;

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
    finallist.insert(1);
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
        finallist.insert(tlist.begin(),tlist.end());
    }
    finlist.reserve(finallist.size());
    for(auto &val:finallist) finlist.push_back(val);
    // sort(finlist.begin(),finlist.end());
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
        auto it=upper_bound(finlist.begin(),finlist.end(),n);
        cout<<(it-finlist.begin())<<'\n';
    }
    // cout<<"Done\n";
    // int i=0;
    // for(auto &val:finallist){
    //      cout<<val<<'\n';
    //      i++;
    //      if((i%20)==0) break;
    // }
    return 0;
}