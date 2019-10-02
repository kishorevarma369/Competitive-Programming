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
    int n,m,k,l,r,ct,cp;
    cin>>n>>m>>k>>l>>r;
    int myprice=INT_MAX;
    for(int i=0;i<n;i++)
    {
        cin>>ct>>cp;
        if(ct<k) ct=min(ct+m,k);
        else if(ct>k) ct=max(k,ct-m);
        if(ct>=l&&ct<=r)
        {
            if(cp<myprice) myprice=cp;
        }
    }
    if(myprice==INT_MAX) myprice=-1;
    cout<<myprice<<'\n';
}

int main()
{
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}