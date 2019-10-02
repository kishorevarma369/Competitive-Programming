#include<bits/stdc++.h>

using namespace std;

int n;

vector<pair<int,int>> v;

int mfind(int i,int j,bool type)
{
    if(i<n&&j>0)
    {
        if(type) return v[j].first-v[i-1].first;
        return v[j].second-v[i-1].second;
    }
    return 0;
}

int solve()
{
    int cost=INT_MAX;
    for(int i=1;i<n;i++)
    {
        cost=min(cost,mfind(1,i-1,false)+mfind(i+1,n-1,true));
    }
    if(cost==INT_MAX) return 0;
    return cost;
}

int main()
{
    int t,val;
    cin>>t;
    while(t--)
    {
        cin>>n;
        v.resize(n,pair<int,int>(0,0));
        int ans=0;
        cin>>val;
        if(val>0) ans++;
        // n--;
        for(int i=1;i<n;i++)
        {
            cin>>val;
            v[i]=v[i-1];
            if(val<0) v[i].first++;
            else v[i].second++;
        } 
        if(val<0) ans++;
        n--;
        ans+=solve();
        cout<<ans<<'\n';
    }
    return 0;
}