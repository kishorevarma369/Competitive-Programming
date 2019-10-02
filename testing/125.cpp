#include<bits/stdc++.h>

using namespace std;
map<int,vector<int>> adj;
int visited[100005];
int nodecount;
void dfs(int node)
{
    for(auto &child:adj[node])
    {
        if(!visited[child])
        {
            visited[child]=1;
            nodecount++;
            dfs(child);
        }
    }
}

int solve()
{
    int n,m,x,y;
    cin>>n>>m;
    adj.clear();
    for(int i=0;i<n;i++) visited[i]=0;
    int ans=0,disconnected=0;
    for(int i=0;i<m;i++)
    {
        cin>>x>>y;
        x--,y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i=0;i<n;i++)
    {
        if(!visited[i]){
            visited[i]=1;
            nodecount=1;
            dfs(i);
            ans+=nodecount-1;
            // cout<<"nodecount="<<nodecount<<'\n';
            // cout<<"disconnected="<<disconnected<<'\n';
            disconnected++;
        }
    }
    ans+=(disconnected-1)*2;
    // cout<<"disconnected"<<disconnected<<'\n';
    // cout<<ans<<'\n';
    return ans;
}

int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cout<<"Case #"<<i<<": "<<solve()<<'\n';
    }
    return 0;
}