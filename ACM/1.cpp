#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long int ll;

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,k,sum=0,fn;
        cin>>n>>k;
        ll a[n],j=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[j];
            if(a[j]<=k) sum+=a[j];
            else j++;
        }
        fn=n;
        n=j;
        if(n>0)
        {
            if(n>1) sort(a,a+n);
            int i=0;
            for(;i<n-1;i++)
            {
                sum+=k;
                if(a[i]==k) continue;
                a[i+1]-=a[i]-k;
            }
            sum+=a[i];
        }
        cout<<sum<<'\n';
    }
    return 0;
}