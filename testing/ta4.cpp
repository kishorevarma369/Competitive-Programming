#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class Graph
{
    public:
    vector<vector<int>> adj;
    Graph()
    {
        
    }
    Graph(int n)
    {
        adj.resize(n,vector<int>(n));
    }
    void add_edge(int a,int b,int cost)
    {
        adj[a][b]=cost;
    }
    ll find_min_tsp_cost();
};

ll Graph::find_min_tsp_cost()
{
    
}

int main()
{
    int n,m;
    cin>>n>>m;
    Graph g(n);
    return 0;
}