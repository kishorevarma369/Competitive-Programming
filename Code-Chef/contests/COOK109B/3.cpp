#include<bits/stdc++.h>

using namespace std;

#define uplim 100005
#define mod 1000000007
#define multiply(val1,val2) (((val1%mod)*(val2%mod))%mod)
#define add(val1,val2) ((val1%mod+val2%mod)%mod)
#define substract(val1,val2) (((val1%mod)-(val2%mod)+mod)%mod)

typedef long long int ll;

void solve()
{
    int n,k;
    cin>>n;
    k=n/2;
    vector<string> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    int ans1=0,ans2=0;
    vector<int> f1(n),f2(n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(j<k&&v[i][j]=='1')
            {
                ans1++;
                f1[i]++;
            }
            else if(j>=k&&v[i][j]=='1')
            {
                ans2++;
                f2[i]++;
            }
        }
    }
    int myans=abs(ans1-ans2),tmp1,tmp2;
    for(int i=0;i<n;i++)
    {
        tmp1=ans1-f1[i]+f2[i];
        tmp2=ans2-f2[i]+f1[i];
        if(abs(tmp1-tmp2)<myans)
        {
            myans=abs(tmp1-tmp2);
        }
    }
    cout<<myans<<'\n';
}

int main()
{
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}