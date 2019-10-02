#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long int ll;

#define mymod 1000000007
#define lim 100001
int two_power[lim];

void pre()
{
    two_power[0]=1;
    for(int i=1;i<lim;i++) two_power[i]=(two_power[i-1]*2)%mymod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    int n,val;
    cin>>n;
    ll ans=0;
    //cin>>val;
    //int found[n+1];
    //for(int i=0;i<=n;i++) found[i]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>val;
        for(int j=1;j<=i;j++) {
            if(val%j==0){
                ans=((ll)ans+two_power[n-i])%mymod;
            } 
            else
            {
                ans=((ll)ans-two_power[n-i]+mymod)%mymod;   
            } 
        }
    }
    cout<<ans<<'\n';
    return 0;
}