/*
https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/traffic-light-2-ee27ba45/
Question :Flight Plan
Solution by :Kishore Varma
*/

#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

void solve()
{
    int n,m,toggle_time,travel_cost,x,y;
    cin>>n>>m>>toggle_time>>travel_cost;
    vector<vector<int>> adj(n);
    for(int i=0;i<m;i++)
    {
        cin>>x>>y;
        x--;
        y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cin>>x>>y;
    x--,y--;
    vector<int> cost(n,0),visited(n,0);
    queue<int> q;
    q.push(x);
    visited[x]=true;
    cost[x]=0;
    vector<vector<int>> path(n);
    path[x]={x};
    while(!q.empty())
    {
        auto node=q.front();
        auto cur_cost=cost[node];
        auto &pres_path=path[node];
        if((cur_cost/toggle_time)&1)
        {
            cur_cost=(cur_cost/toggle_time+1)*toggle_time;
        }
        q.pop();
        for(auto child:adj[node])
        {
            auto tmp_cost=cur_cost+travel_cost;
            if(!visited[child])
            {
                cost[child]=tmp_cost;
                visited[child]=true;
                path[child]=pres_path;
                path[child].push_back(child);
                q.push(child);
            }
            else if(cost[child]>tmp_cost)
            {
                q.push(child);
                pres_path.push_back(child);
                cost[child]=tmp_cost;
                path[child]=pres_path;
                pres_path.pop_back();
            }
            else if(cost[child]==tmp_cost)
            {
                pres_path.push_back(child);
                if(path[child]>pres_path)
                {
                    path[child]=pres_path;
                }
                pres_path.pop_back();
            }
        }
    }
    cout<<path[y].size()<<'\n';
    for(auto node:path[y]) cout<<node+1<<' ';
    cout<<'\n';
}

int main()
{
    solve();
    return 0;
}

