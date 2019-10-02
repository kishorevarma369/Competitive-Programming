#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

map<int,int> visited;

int a,b,mmin,mmax;

void bfs()
{
    int x,pos;
    queue<int> q;
    q.push(a);
    visited[a]=1;
    while(!q.empty())
    {
        x=q.front();
        q.pop();
        pos=visited[x];
        if(x-1>0&&!visited[x-1])
        {
            q.push(x-1);
            visited[x-1]=pos+1;
            if(x-1==b) break;   
        }
        if(x+3<mmax&&!visited[x+3])
        {
            q.push(x+3);
            visited[x+3]=pos+1;
            if(x+3==b) break;   
        }
        if(2*x<mmax&&!visited[2*x]){
            q.push(2*x);
            visited[2*x]=pos+1;
            if(2*x==b) break;  
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        if(a<b)
        {
            visited.clear();
            mmax=max(2*b,b+3);
            bfs();
            cout<<visited[b]-1<<'\n';
        }
        else 
        {
            cout<<a-b<<'\n';
        }
    }    
    return 0;
}