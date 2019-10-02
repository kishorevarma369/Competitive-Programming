#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool cmp(pair<int,int> &a,pair<int,int> &b)
{
    if(a.first<b.first)
        return true;
    return false;
}
ll knp(vector<pair<int,int>> &v,ll cap,int start,ll val,ll w)
{
    if(w>cap)
        return 0;
    else if(w==cap)
        return val+v[start].second;
    ll a=knp(v,cap,start+1,val+v[start].second,w+v[start].first);
    ll b=knp(v,cap,start+1,val,w);
    if(a>b)
        return a;
    return b;
}
int main()
{
    int n,x,y;
    ll sum=0;
    cin>>n;
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++)
    {
        cin>>x>>y;
        v.push_back(make_pair(x,y));
        sum+=x;
        cout<<sum;
    }
    sort(v.begin(),v.end(),cmp);
    for(ll i=1;i<=sum;i++)
    {
        cout<<knp(v,i,0,0,0);
    }
}