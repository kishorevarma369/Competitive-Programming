#include<bits/stdc++.h>
using namespace std;

typedef struct {
    int x,y;
}point;

point gp;

bool cmp (const point& p,const point&q) 
{
    if(q.y!=p.y) return q.y<p.y;
    return p.x<q.x;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<point> v(n);
        for(int i=0;i<n;i++)
        {
            cin>>v[i].x>>v[i].y;
        }
        sort(v.begin(),v.end(),cmp);
        int mym=v[0].x,ans=1;
        for(int i=1;i<v.size();i++)
        {
            if(v[i].x>=mym)
            {
                mym=v[i].x;
                ans++;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}