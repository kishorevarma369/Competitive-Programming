#include<bits/stdc++.h>

using namespace std;

#define rep(i,beg,end,inc) for(i=beg;i<end;i+=inc) 

typedef long long int ll;

int main(int argc, char const *argv[])
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,i,p;
        cin>>n;
        ll a[n];
        rep(i,0,n,1)
        {
            cin>>a[i];
        }
        p=a[n-1]+1;
        for(i=n-2;i>=0;i--)
        {
            if(p<a[i]) p=a[i];
            p++;
        }
        cout<<p-1<<'\n';
    }
    return 0;
}
