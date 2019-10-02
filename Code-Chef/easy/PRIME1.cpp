#include<bits/stdc++.h>

using namespace std;

vector<int> primes;
int primepos;

#define uplimit 1000000001

bool isprime(int val)
{
    for(int i=0;i<primepos&&primes[i]*primes[i]<=val;i++)
    {
        if(val%primes[i]==0)
        {
            return false;
        }
    }
    return true;
}

void prime_gen()
{
    int n=sqrt(uplimit)+1;
    primes.resize(n+5);
    primes[primepos++]=2;
    for(int i=3;i<=n;i++)
    {
        if(isprime(i)) primes[primepos++]=i;
    }
}

void calc()
{
    int a,b;
    cin>>a>>b;
    if(a==1) a++;
    for(int i=a;i<=b;i++)
    {
        if(isprime(i)) cout<<i<<'\n';
    }
    cout<<'\n';
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    prime_gen();
    int t;
    cin>>t;
    while(t--)
    {
        calc();
    }
    return 0;
}
