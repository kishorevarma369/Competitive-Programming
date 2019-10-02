#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;

int m,n;
ll clib,croad;



// void process()
// {
//     for(auto &road:roads)
//     {
//         sort(road.begin(),road.end());
//     }
// }


ll bfs(int i,vector<vector<int>> &roads,vector<bool> &visited)
{
    queue<int> q;
    q.push(i);
    int node,count=1;
    visited[i]=true;
    while(!q.empty())
    {
        node=q.front();
        q.pop();
        for(auto &road:roads[node])
        {
            if(!visited[road])
            {
                q.push(road);
                visited[road]=true;
                count++;
            }
        }
    }
    if(clib<=croad) return clib*count;   
    else return clib+(count-1)*croad;
}

int main(int argc, char const *argv[])
{
    int t;
    cin>>t;
    while(t--)
    {
        int ebegin,eend;
        ll ans=0;
        cin>>n>>m>>clib>>croad;
        vector<vector<int>> roads(n);
        vector<bool> visited(n,0);
        for(int i=0;i<m;i++)
        {
            cin>>ebegin>>eend;
            ebegin--;
            eend--;
            roads[ebegin].push_back(eend);
            roads[eend].push_back(ebegin);
        }
        // process();
        for(int i=0;i<n;i++)
        {
            if(!visited[i]) ans+=bfs(i,roads,visited);
        }
        cout<<ans<<'\n';

    }
    return 0;
}
