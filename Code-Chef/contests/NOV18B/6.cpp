#include<bits/stdc++.h>

using namespace std;

const int mymod=1e9+7;
#define cpoint 2002
typedef long long int ll;

ll two_power[cpoint];

ll ncr[cpoint][cpoint];

void calc()
{
    two_power[0]=1;
    for(int i=1;i<cpoint;i++) two_power[i]=(two_power[i-1]*2)%mymod;
    for(int i=0;i<cpoint;i++) ncr[i][0]=1;
    for(int i=1;i<cpoint;i++)
    {
        for(int j=1;j<=i;j++) ncr[i][j]=(ncr[i-1][j-1]+ncr[i-1][j])%mymod;
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
        int a[cpoint]={0},l[cpoint]={0},g[cpoint]={0};
        for(int i=0;i<n;i++) cin>>val,a[val]++;
        for(int i=1;i<cpoint;i++) l[i]=l[i-1]+a[i-1];
        for(int i=cpoint-2;i>=0;i--) g[i]=g[i+1]+a[i+1];
        ll ans=two_power[n-1];
        int p,q,r,d;
        ll tans,k;
        for(int i=1;i<2002;i++)
        {
            q=a[i];
            if(q>=2)
            {
                tans=0;
                p=l[i];
                r=g[i];
                d=min(p,r);
                for(int j=0;j<=d;j++) tans=(tans+(ncr[p][j]*ncr[r][j])%mymod)%mymod;
                k=(two_power[q-1]-1);
                if(k<0) k+=mymod;
                ans=(ans+(k*tans)%mymod)%mymod;
                tans=0;
                for(int j=0;j<=d;j++) tans=(tans+((ncr[p][j+1]*ncr[r][j])%mymod+(ncr[p][j]*ncr[r][j+1])%mymod)%mymod)%mymod;
                k=(two_power[q-1]-q);
                if(k<0) k+=mymod;
                ans=(ans+(k*tans)%mymod)%mymod;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}