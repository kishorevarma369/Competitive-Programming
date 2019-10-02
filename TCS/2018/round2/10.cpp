#include<bits/stdc++.h>

using namespace std;

bitset<50> b;
int n,ans=0;

bool valid(bitset<50> &t)
{
    for(int i=0;i<n;i++)
    {
        if(t[i])
        {
            
        }
    }
}

void bfs()
{
    queue<bitset<50>> q;
    map<bitset<50>,bool> found;
    q.push(b);
    found[b]=1;
    bitset<50> pres;
    while(!q.empty())
    {
        pres=q.front();
        q.pop();
        for(int i=0;i<n;i++)
        {

        }
    }
}

int main()
{
    
    cin>>n;
    bfs();
    return 0;
}