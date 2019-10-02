#include<bits/stdc++.h>

using namespace std;

int solve()
{
    int a,b,c,x,y,steps,r,s;
    cin>>a>>b>>c;
    if(a==c||b==c) return 1;
    map<pair<int,int>,int> visited;
    queue<pair<int,int>> q;
    pair<int,int> pr;
    q.push({0,0});
    visited[{0,0}]=0;
    auto tsteps=visited.begin();
    while(!q.empty())
    {
        pr=q.front();
        steps=visited[pr];
        tie(x,y)=pr;
        q.pop();
        if(x==0)
        {
            pr={a,y};
            tsteps=visited.find(pr);
            if(tsteps==visited.end()) {
                visited[pr]=steps+1;
                q.push(pr);
                if(pr.first==c||pr.second==c) return steps+1;
            }         
        }
        if(y==0)
        {
            pr={x,b};
            tsteps=visited.find(pr);
            if(tsteps==visited.end()) {
                visited[pr]=steps+1;
                q.push(pr);
                if(pr.first==c||pr.second==c) return steps+1;
            }
        }
        if(x==a)
        {
            pr={0,y};
            tsteps=visited.find(pr);
            if(tsteps==visited.end()) {
                visited[pr]=steps+1;
                q.push(pr);
                if(pr.first==c||pr.second==c) return steps+1;
            }         
        }
        if(y==b)
        {
            pr={x,0};
            tsteps=visited.find(pr);
            if(tsteps==visited.end()) {
                visited[pr]=steps+1;
                q.push(pr);
                if(pr.first==c||pr.second==c) return steps+1;
            }
        }
        pr={min(x+y,a),y-(min(x+y,a)-x)};
        tsteps=visited.find(pr);
        if(tsteps==visited.end()) {
            visited[pr]=steps+1;
            q.push(pr);
            if(pr.first==c||pr.second==c) return steps+1;
        }
        pr={x-(min(x+y,b)-y),min(x+y,b)};
        tsteps=visited.find(pr);
        if(tsteps==visited.end()) {
            visited[pr]=steps+1;
            q.push(pr);
            if(pr.first==c||pr.second==c) return steps+1;
        }
    }
    return -1;
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        auto x=solve();
        cout<<x<<'\n';
    }
    return 0;
}