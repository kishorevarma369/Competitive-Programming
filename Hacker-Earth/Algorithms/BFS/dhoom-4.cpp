/*
https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/traffic-light-2-ee27ba45/
Question :Dhoom 4
Solution by :Kishore Varma
*/

#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
#define mod 100000
// void solve()
// {
//     int key,locks_key;
//     cin>>key>>locks_key;
//     int n,val;
//     cin>>n;
//     set<int> keys;
//     for(int i=0;i<n;i++) cin>>val,keys.insert(val);
//     queue<int> q; 
//     // set<int> visited;
//     map<int,int> cost;
//     if(key==locks_key){
//         cout<<"0\n";
//         return;
//     }
//     q.push(key);
//     cost[key]=0;
//     while(!q.empty())
//     {
//         auto node=q.front();
//         q.pop();
//         auto node_cost=cost[node];
//         auto t_cost=0;
//         for(auto key:keys)
//         {
//             t_cost=(1ll*node*key)%mod;
//             auto it=cost.find(t_cost);
//             if(it==cost.end())
//             {
//                 cost[t_cost]=node_cost+1;
//                 q.push(t_cost);
//             }
//             else
//             {
//                 if(it->second>(node_cost+1))
//                 {
//                     q.push(t_cost);
//                     it->second=node_cost+1;
//                 }
//             }
//         }
//     }
//     auto it=cost.find(locks_key);
//     if(it==cost.end()) cout<<"-1\n";
//     else cout<<it->second<<'\n';
// }

void solve()
{
    int key,locks_key;
    cin>>key>>locks_key;
    int n,val;
    cin>>n;
    set<int> keys_set;
    for(int i=0;i<n;i++) cin>>val,keys_set.insert(val);
    vector<int> keys(keys_set.begin(),keys_set.end());
    queue<int> q; 
    // set<int> visited;
    vector<int> cost(mod+1,-1);
    if(key==locks_key){
        cout<<"0\n";
        return;
    }
    q.push(key);
    cost[key]=0;
    while(!q.empty())
    {
        auto node=q.front();
        q.pop();
        auto node_cost=cost[node];
        auto child=0;
        for(auto key:keys)
        {
            child=(1ll*node*key)%mod;
            if(cost[child]==-1)
            {
                cost[child]=node_cost+1;
                q.push(child);
            }
            else
            {
                if(cost[child]>node_cost+1)
                {
                    q.push(child);
                    cost[child]=node_cost+1;
                }
            }
        }
    }
    cout<<cost[locks_key]<<'\n';
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

