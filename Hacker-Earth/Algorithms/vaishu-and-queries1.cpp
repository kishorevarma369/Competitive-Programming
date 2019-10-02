#include<bits/stdc++.h>

using namespace std;
#define all(x) x.begin(),x.end()
int n;
vector<pair<int,int>> v;
map<tuple<int,int,int>,int> cache;

int f(int pos,int x,int y)
{
    if(pos<n&&x>=0&&y>=0)
    {
        auto it=cache.find(make_tuple(pos,x,y));
        if(it!=cache.end()) return it->second;
        int k;
        if(x>=v[pos].first&&y>=v[pos].second) k=max(1+f(pos+1,x-v[pos].first,y-v[pos].second),f(pos+1,x,y));
        else k=f(pos+1,x,y);
        cache[make_tuple(pos,x,y)]=k;
        return k;
    }
    return 0;
}

int main()
{
    cin>>n;
    v.resize(n);
    string s;
    int r=0,b=0;
    for(auto &pr:v)
    {
        r=b=0;
        cin>>s;
        for(auto ch:s) 
            if(ch=='R') r++;
            else b++;
        pr.first=r;
        pr.second=b;
    }
    int t,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;
        cout<<f(0,x,y)<<'\n';
    }
    return 0;
}