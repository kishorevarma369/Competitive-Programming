#include<bits/stdc++.h>

using namespace std;
#define uplim 100001
int prime_count[uplim];

void pre()
{
    for(int i=2;i<uplim;i+=2) prime_count[i]++;
    for(int i=3;i<uplim;i+=2)
    {
        if(prime_count[i]==0)
        {
            for(int j=i;j<uplim;j+=i) prime_count[j]++;
        }
    }
}

int main()
{
    int t;
    pre();
    cin>>t;
    while(t--)
    {
        int n,a[uplim]={0},val,ans=0;
        cin>>n;
        for(int i=0;i<n;i++) cin>>val,a[val]++;
        for(int i=2;i<uplim;i++)
        {
            val=0;
            for(int j=i;j<uplim;j+=i)
            {
                val+=a[j];
            }
            ans=max(ans,prime_count[i]*val);
        }
        cout<<ans<<'\n';
    }
    return 0;
}