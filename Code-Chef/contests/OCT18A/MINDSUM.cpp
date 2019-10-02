#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;

ll sumofdigits(ll num)
{
    ll val=0;
    while(num)
    {
        val+=num%10;
        num/=10;
    }
    return val;
}

ll digitsum(ll val)
{
    while(val>9)
    {
        val=sumofdigits(val);
    }
    return val;
}

void solve()
{
    ll n,d,val,tval,steps,maxval;
    cin>>n>>d;
    map<ll,ll> visited;
    queue<ll> mq;
    mq.push(n);
    visited[n]=0;
    int i=0;
    while(!mq.empty())
    {
        val=mq.front();
        steps=visited[val];
        mq.pop();
        tval=sumofdigits(val);
        if(visited.find(tval)==visited.end())
        {
            visited[tval]=steps+1;
            mq.push(tval);
        }
        tval=val+d;
        if(visited.find(tval)==visited.end())
        {
            visited[tval]=steps+1;
            mq.push(tval);
        }
        i++;
        if((i%10000)==0) break;
        //if((i%1000)==0) cout<<"least possible "<<visited.begin()->first<<" max val "<<maxval<<'\n';
    }
    tie(maxval,val)=*visited.begin();
    cout<<maxval<<' '<<val<<'\n';
    //536229434
// 992312874
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}