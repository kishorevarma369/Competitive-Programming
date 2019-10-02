/*
https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/traffic-light-2-ee27ba45/
Question :Game
Solution by :Kishore Varma
*/

#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

void solve()
{
    int n=100,m,max_jump,dest,x,y;
    cin>>m>>max_jump>>dest;
    dest--;
    vector<vector<int>> adj(n);
    bool proceed=true;
    for(int i=0;i<m;i++)
    {
        cin>>x>>y;
        x--;
        y--;
        adj[x].push_back(y);
        // adj[y].push_back(x);
        if(x==dest) proceed=false;
    }
    if(!proceed)
    {
        cout<<"-1\n";
        return;
    }
    x=0;
    vector<int> cost(n,0),visited(n,0);
    queue<int> q;
    q.push(x);
    visited[x]=true;
    // cost[x]=0;
    while(!q.empty())
    {
        auto node=q.front();
        auto cur_cost=cost[node];
        q.pop();
        if(adj[node].size())
        {
            for(auto child:adj[node])
            {
                if(!visited[child])
                {
                    visited[child]=1;
                    cost[child]=cur_cost;
                    q.push(child);
                }
                else{
                    if(cost[child]>cur_cost)
                    {
                        cost[child]=cur_cost;
                        q.push(child);
                    }
                }
            }
        }
        else
        {
            auto upto=min(99,node+max_jump);
            cur_cost+=1;
            for(int child=node;child<=upto;child++)
            {
                if(!visited[child])
                {
                    visited[child]=1;
                    cost[child]=cur_cost;
                    q.push(child);
                }
                else{
                    if(cost[child]>cur_cost)
                    {
                        cost[child]=cur_cost;
                        q.push(child);
                    }
                }
            }
        }
    }
    if(!visited[dest]) cout<<"-1\n";
    else cout<<cost[dest]<<'\n';    
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}

