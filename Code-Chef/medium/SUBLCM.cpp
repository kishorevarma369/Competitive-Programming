#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define uplim 1000000
vector<int> primes;
vector<int> primefactors[uplim];
int pparr[1000001];

bool isprime(int val)
{
    bool prime=true;
    for(auto primeno:primes)
    {
        if(primeno*primeno>val){
            return true;
        }
        if((val%primeno)==0){
            return false;
        }
    }
    return true;
}

void prime_gen()
{
    primes.reserve(78500);
    primes.push_back(2);
    for(int i=2;i<=uplim;i+=2) primefactors[i].push_back(2);
    for(int i=3;i<1000000;i+=2)
    {
        if(isprime(i))
        {
            primes.push_back(i);
            for(int j=i;j<=uplim;j+=i) primefactors[j].push_back(i);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    prime_gen();
    int t,n,val,x;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<uplim;i++) pparr[i]=-2;
        int maxsize=0,ans=0,beg=-1;
        for(int i=0;i<n;i++){ 
            cin>>val;
            if(val==1)
            {
                ans++;
                continue;
            }
            auto &primelist=primefactors[val];
            bool valid=true;
            int shiftpos=0;
            for(auto &primeno:primelist)
            {
                if(pparr[primeno]>beg)
                {
                    valid=false;
                    shiftpos=max(shiftpos,pparr[primeno]);
                }
                pparr[primeno]=i;
            }
            if(valid)
            {
                ans++;
                if(ans>maxsize) maxsize=ans;
            }
            else
            {
                if(ans>maxsize) maxsize=ans;
                ans=i-shiftpos;
                beg=shiftpos;
            }
        }
        if(ans>maxsize) maxsize=ans;
        if(maxsize<2) cout<<"-1\n";
        else cout<<maxsize<<'\n';
    }
    return 0;
}