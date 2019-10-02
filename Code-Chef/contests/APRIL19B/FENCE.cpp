#include<bits/stdc++.h>

using namespace std;
// time taken 2 hours
int n,m,k;

bool isvalid(int x,int y)
{
    if(x>0&&x<=n&&y>0&&y<=m) return true;
    return false;
}

int ax[]={1,0,-1,0};
int ay[]={0,1,0,-1};
map<int,map<int,bool>> matrix;

void solve()
{
    int ans=0,cou;
    cin>>n>>m>>k;
    int x,y;
    matrix.clear();
    for(int i=0;i<k;i++)
    {
        cin>>x>>y;
        matrix[x][y]=false;
    }
    for(auto &row:matrix)
    {
        x=row.first;
        for(auto &col:row.second)
        {
            y=col.first;
            cou=0;
            for(int i=0;i<4;i++)
            {
                if(isvalid(x+ax[i],y+ay[i]))
                {
                    if(ax[i]==0)
                    {
                        if(row.second.find(y+ay[i])==row.second.end())
                        {
                            cou++;
                        }
                    }
                    else{
                        auto rptr=matrix.find(x+ax[i]);
                        if(rptr!=matrix.end())
                        {
                            auto &trow=rptr->second;
                            if(trow.find(y)==trow.end())
                            {
                                cou++;
                            }
                        }
                        else cou++;
                    }
                }
                else cou++;
            }
            ans+=cou;
        }
    }
    cout<<ans<<'\n';
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