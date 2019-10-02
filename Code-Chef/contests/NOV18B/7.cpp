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
        ll n,val,a[cpoint]={0};
        cin>>n;
        for(int i=0;i<n;i++) cin>>val,a[val]++;
        ll ans=two_power[n-1],less_than=0,greater_than=0,mymin;
        for(int i=1;i<cpoint;i++)
        {
            less_than+=a[i-1];
            val=a[i];
            greater_than=n-less_than-val;
            if(val>=2)
            {
                for(int k=0;k<val;k++)
                {
                    for(int j=k+1;j<val;j++)
                    {
                        mymin=min(greater_than+val-j-1,less_than);
                        if(mymin<0) continue;
                        //for(int l=0;l<=mymin;l++) ans=(ans+(ncr[greater_than+val-j-1][l]*ncr[less_than][l])%mymod)%mymod;
                        ans=(ans+ncr[less_than+greater_than+val-j-1][mymin])%mymod;
                    }
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}