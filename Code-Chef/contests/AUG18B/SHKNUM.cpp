#include<bits/stdc++.h>

using namespace std;

#define mymod 1000000007ll

typedef long long int ll;


ll nextPowerOf2(ll n)
{
    ll p = 1;
    if (n && !(n & (n - 1)))
        return n;
 
    while (p < n) 
        p <<= 1;
     
    return p;
}

int main(int argc, char const *argv[])
{
    ll a,b,t,p,q,n,t1,t2,mymin=INT64_MAX;
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n==1)
        {
            cout<<"2\n";
            continue;
        }
        b=__builtin_popcount(n);
        if(b==2)
        {
            cout<<"0\n";
            continue;
        }
        if(b<2)
        {
            cout<<"1\n";
            continue;
        }
        q=nextPowerOf2(n);
        p=q>>1;
        q++;
        mymin=abs(q-n);
        a=1;
        while(a<p)
        {
            t1=p|a;
            mymin=min(mymin,abs(n-t1));
            a<<=1;
        }
        cout<<mymin<<'\n';
    }
    return 0;
}
