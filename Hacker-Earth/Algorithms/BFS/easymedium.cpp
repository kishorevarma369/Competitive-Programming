/*
https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/easymedium/
Question : Zeta and thanos
Solution by :Kishore Varma
*/

#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
#define mod 100000

int ax[]={1,-1,0,0};
int ay[]={0,0,1,-1};

int n,m,sx,sy,fx,fy,tx,ty;

int v[1001][1001];
pair<int,int> cost[1001][1001];
bool visited[1001][1001];

bool isvalid(int x,int y)
{
    if(x>=0&&y>=0&&x<n&&y<m&&v[x][y]!=10) return true;
    return false;
}

void solve()
{
    cin>>n>>m;
    char ch;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>ch;
            while(ch==' ');
            if(ch=='*') v[i][j]=10;
            else v[i][j]=ch-'0';
        }
    }
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<m;j++)
    //     {
    //         cout<<v[i][j]<<' ';
    //     }
    //     cout<<'\n';
        
    // }
    // vector<vector<pair<int,int>>> cost(n,vector<pair<int,int>>(m));
    cin>>sx>>sy;
    sx--,sy--;
    queue<pair<int,int>> q;
    q.push({sx,sy});
    cost[sx][sy]={0,v[sx][sy]};
    visited[sx][sy]=1;
    while(!q.empty())
    {
        auto pr=q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            tx=pr.first+ax[i];
            ty=pr.second+ay[i];
            if(isvalid(tx,ty))
            {
                auto pres_cost=cost[pr.first][pr.second];
                pres_cost.first++;
                pres_cost.second+=v[tx][ty];
                if(!visited[tx][ty])
                {
                    visited[tx][ty]=1;
                    cost[tx][ty]=pres_cost;
                    q.push({tx,ty});
                }
                else
                {
                    if(cost[tx][ty].first>pres_cost.first)
                    {
                        cost[tx][ty]=pres_cost;
                        q.push({tx,ty});
                    }
                    else if(cost[tx][ty].first==pres_cost.first&&cost[tx][ty].second<pres_cost.second)
                    {
                        cost[tx][ty]=pres_cost;
                        q.push({tx,ty});
                    }
                }
                
            }
        }
    }
    int qt;
    cin>>qt;
    while(qt--)
    {
        cin>>fx>>fy;
        fx--,fy--;
        if(!visited[fx][fy]) cout<<"-1 -1\n";
        else cout<<cost[fx][fy].first<<' '<<cost[fx][fy].second<<'\n';
    }
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t=1;
    // cin>>t;
    while(t--) solve();
    return 0;
}

