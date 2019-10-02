#include<bits/stdc++.h>

using namespace std;

#define mymod 1000000007

typedef unsigned long long int ll;

ll two_power[1001];

void calc()
{
    ll val=1;
    for(int i=0;i<1001;i++)
    {
        two_power[i]=val;
        val<<=1;
        val%=mymod;
    }
}

int main()
{
    int t;
    cin>>t;
    calc();
    while(t--)
    {
        int n,val;
        cin>>n;
        ll ans=two_power[n-1];
        int a[2002]={0},pref[2002]={0};
        for(int i=0;i<n;i++)
        {
            cin>>val;
            a[val]++;
        }
        for(int i=1;i<n;i++)
        {
            pref[i]=pref[i-1]+a[i-1];
        }
        for(int i=1;i<2001;i++)
        {
            
        }

    }
    return 0;
}