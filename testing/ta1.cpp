#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef struct point{
    int weight,val;
    point(){
        weight=val=0;
    }
    point(int a,int b)
    {
        weight=a;
        val=b;
    }
    bool operator < (const point &a) const {
      return weight<a.weight;
   }

} item;

int main()
{
    int n,x,y;
    ll sum=0;
    cin>>n;
    vector<item> v;
    v.reserve(n+1);
    v.push_back({0,0});
    for(ll i=1;i<=n;i++)
    {
        cin>>x>>y;
        v.push_back({x,y});
        sum+=x;
    }
    vector<vector<ll>> ans(n+1,vector<ll>(sum+1));
    // sort(v.begin(),v.end());
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=sum;j++)
        {
            if(j-v[i].weight>=0)
            {
                ans[i][j]=max(ans[i-1][j],ans[i-1][j-v[i].weight]+v[i].val);
            }
            else ans[i][j]=ans[i-1][j];
        }
    }
    for(ll j=1;j<=sum;j++) cout<<ans[n][j]<<' ';
    return 0;
}