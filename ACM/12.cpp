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
        priority_queue<ll> m;
        for(int i=0;i<n;i++) cin>>val,m.push(val);
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
        ll cans=0,creq=0;
        while(ppreq>0&&m.size())
        {
            creq=m.top();
            m.pop();
            if(creq/2) m.push(creq/2);
            ppreq-=creq;
            cans++;
        }
        if(ppreq<=0){  cout<<cans<<'\n';}
        else cout<<"RIP\n";
    }
    return 0;
}