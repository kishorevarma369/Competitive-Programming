/*
https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/traffic-light-2-ee27ba45/
Question :Minimum Cost
Solution by :Kishore Varma
*/

#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

vector<int> v(50001);

vector<int> cost(50001,0),visited(50001,0);

void visit_all_nodes(int x,queue<int> &q,int cur_cost)
{
    while(!visited[x]||cost[x]>cur_cost)
    {
        visited[x]=true;
        cost[x]=cur_cost;
        q.push(x);
        x=v[x];
    }
}

void solve()
{
    int n,x;
    cin>>n;
    for(int i=0;i<n;i++) cin>>v[i],v[i]--,visited[i]=0,cost[i]=0;
    queue<int> q;
    x=0;
    visit_all_nodes(x,q,0);
    while(!q.empty())
    {
        auto node=q.front();
        auto cur_cost=cost[node]+1;
        q.pop();
        if(node+1<n) visit_all_nodes(node+1,q,cur_cost);
        if(node-1>=0) visit_all_nodes(node-1,q,cur_cost);
    }
    cout<<cost[n-1]<<'\n';
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



// void solve()
// {
//     int n,x;
//     cin>>n;
//     for(int i=0;i<n;i++) cin>>v[i],v[i]--,visited[i]=0,cost[i]=0;
//     queue<int> q;
//     x=0;
//     q.push(x);
//     visited[x]=true;
//     auto parent_x=v[x];
//     while(!visited[parent_x])
//     {
//         visited[parent_x]=true;
//         q.push(parent_x);
//         parent_x=v[parent_x];
//     }
//     int up_cost=INT_MAX;
//     // cost[x]=0;
//     while(!q.empty())
//     {
//         auto node=q.front();
//         auto cur_cost=cost[node];
//         q.pop();
//         if(cur_cost>up_cost) continue;
//         auto free_travel_node=v[node];
//         if(!visited[free_travel_node]||cost[free_travel_node]>cur_cost)
//         {
//             if(!visited[free_travel_node])
//             {
//                 visited[free_travel_node]=1;
//                 parent_x=v[free_travel_node];
//                 cost[free_travel_node]=cur_cost;
//                 while(!visited[parent_x])
//                 {
//                     visited[parent_x]=true;
//                     q.push(parent_x);
//                     parent_x=v[parent_x];
//                 }
//             }
//             cost[free_travel_node]=cur_cost;
//             if(free_travel_node==(n-1)) up_cost=cur_cost;
//             else if(cur_cost<up_cost) q.push(free_travel_node);
//         }
//         cur_cost++;
//         if(cur_cost>up_cost) continue;
//         if(node+1<n)
//         {
//             free_travel_node=node+1;
//             if(!visited[free_travel_node]||cost[free_travel_node]>cur_cost)
//             {
//                 visited[free_travel_node]=1;
//                 cost[free_travel_node]=cur_cost;
//                 if(free_travel_node==(n-1)) up_cost=cur_cost;
//                 else if(cur_cost<up_cost) q.push(free_travel_node);
//             }
//         }
//         if(node-1>=0)
//         {
//             free_travel_node=node-1;
//             if(!visited[free_travel_node]||cost[free_travel_node]>cur_cost)
//             {
//                 visited[free_travel_node]=1;
//                 cost[free_travel_node]=cur_cost;
//                 if(free_travel_node==(n-1)) up_cost=cur_cost;
//                 else if(cur_cost<up_cost) q.push(free_travel_node);
//             }
//         }
        
//     }
//     cout<<cost[n-1]<<'\n';    
// }