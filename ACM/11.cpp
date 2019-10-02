#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        ll n,a,b,x,y,z,val;
        cin>>n>>a>>b>>x>>y>>z;
        map<ll,int> m;
        for(int i=0;i<n;i++) cin>>val,m[val]++;
        if(z<=b)
        {
            cout<<"RIP\n";
            continue;
        }
        ll atthattime=(z-b)/y;
        if(((z-b)%y)==0) atthattime--;
        ll ppusers=a+x*atthattime;
        ll ppreq=z-ppusers;
        if(ppreq<=0){
            cout<<"0\n";
            continue;
        }
        ll tval,cans=0,tans=0,presanscount,creq;
        vector<ll> tmpv;
        tmpv.reserve(100);
        for(auto it=m.rbegin();it!=m.rend();it++)
        {
            tval=it->first;
            creq=ppreq/tval;
            if(it->second>creq)
            {
                cans+=creq;
                break;
            }
            presanscount=tans=0;
            if(tans>=ppreq){
                cans+=presanscount;
                break;
            }
            cans+=presanscount;
        }
    }
    return 0;
}