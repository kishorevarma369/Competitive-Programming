#include<bits/stdc++.h>

using namespace std;
#define all(x) x.begin(),x.end()
int n;
vector<pair<int,int>> v;
int cache[105][105][105];
int f(int pos,int x,int y)
{
    if(pos<n&&x>=0&&y>=0)
    {
        if(cache[pos][x][y]!=-1) return cache[pos][x][y];
        int k;
        if(x>=v[pos].first&&y>=v[pos].second) k=max(1+f(pos+1,x-v[pos].first,y-v[pos].second),f(pos+1,x,y));
        else k=f(pos+1,x,y);
        cache[pos][x][y]=k;
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
    for(int i=0;i<105;i++)
        for(int j=0;j<105;j++)
            for(int k=0;k<105;k++) cache[i][j][k]=-1;
    int t,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;
        cout<<f(0,x,y)<<'\n';
    }
    return 0;
}

/*
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

*/