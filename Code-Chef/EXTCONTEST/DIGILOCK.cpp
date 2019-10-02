#include<bits/stdc++.h>

using namespace std;

map<tuple<int,int,int>,bool> visited; 

#define uplim 100001

int a[uplim][2],b[uplim][2],c[uplim][2],n,q;

void pre(int lol[][2])
{
    int prev,mprev,val;
    cin>>mprev;
    prev=val=mprev;
    for(int i=1;i<n;i++)
    {
        cin>>val;
        lol[prev][1]=val;
        lol[val][0]=prev;
        prev=val;
    }
    lol[mprev][0]=val;
    lol[val][1]=mprev;
}

void bfs()
{
    queue<tuple<int,int,int>> q;
    int val1,val2,val3;
    cin>>val1>>val2>>val3;
    tuple<int,int,int> t={val1,val2,val3},r,s;
    q.push(t);
    visited[t]=true;
    while(!q.empty())
    {
        r=q.front();
        tie(val1,val2,val3)=r;
        q.pop();
        s={a[val1][0],a[val2][0],val3};
        if(visited.find(s)==visited.end())
        {
            visited[s]=true;
            q.push(s);
        } 
        s={a[val1][1],a[val2][1],val3};
        if(visited.find(s)==visited.end())
        {
            visited[s]=true;
            q.push(s);
            //hello
        } 
        s={val1,a[val2][1],a[val3][1]};
        if(visited.find(s)==visited.end())
        {
            visited[s]=true;
            q.push(s);
        } 
        s={val1,a[val2][0],a[val3][0]};
        if(visited.find(s)==visited.end())
        {
            visited[s]=true;
            q.push(s);
        } 
    }
}

int main()
{
    cin>>n>>q;
    pre(a);pre(b);pre(c);
    bfs();
    int val1,val2,val3;
    tuple<int,int,int> tmp;
    while(q--)
    {
        cin>>val1>>val2>>val3;
        tmp={val1,val2,val3};
        if(visited.find(tmp)==visited.end()) cout<<"NO\n";
        else cout<<"YES\n";
    }
    return 0;
}