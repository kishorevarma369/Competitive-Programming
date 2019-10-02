#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define uplim 100001
typedef long long int ll;
ll prime[uplim+2],prime_count=1,count[uplim];
ll l,r;
void gen_prime()
{
    prime[1]=2;
    prime_count++;
    int isprime;
    for(int i=3;prime_count<uplim;i+=2)
    {
        isprime=1;
        for(int j=1;j<prime_count&&prime[j]*prime[j]<=i;j++)
        {
            if(i%prime[j]==0){ isprime=0;break;}
        }
        if(isprime) prime[prime_count++]=i;
    }
}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    gen_prime();
    ll n;
    scanf("%lld",&n);
    ll a[n],b[n],flag,j;
    for(ll i=0;i<n;i++) scanf("%lld",a+i),count[a[i]]=1;
    for(ll i=0;i<n;i++)
    {
        flag=0;
        for(ll j=a[i]+a[i];j<uplim;j+=a[i]) if(count[j]) {flag=j;break;}
        if(flag) printf("%lld ",prime[flag]);
        else printf("0 ");
    }
    return 0;
}
