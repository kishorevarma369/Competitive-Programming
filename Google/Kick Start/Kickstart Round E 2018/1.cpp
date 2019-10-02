#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
    ll t,n,k,val,i,x,y,pd,rem,mymax,ans=0;
    map<ll,ll> v;
    //freopen("a.txt","r",stdi);
        ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    for(int p=1;p<=t;p++)
    {
        ans=rem=0;
        cin>>n>>k;
        v.clear();
        for(i=0;i<n;i++)
        {
            cin>>val;
            v[val]++;
        }
        pd=0;
        mymax=k;
        for(auto &P:v)
        {
            tie(x,y)=P;
            if(x<=pd) break;
            while(x>pd&&y)
            {
                if(y<mymax)
                {
                    mymax-=y;
                    ans+=y;
                    y=0;
                }
                else
                {
                    ans+=mymax;
                    y-=mymax;
                    pd++;
                    mymax=k;
                }
            }
        }
        cout<<"Case #"<<p<<": "<<ans<<'\n';
        //cout<<ans<<'\n';
    }
    return 0;
}