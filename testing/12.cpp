#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;

void print(map<string,string> &parent,string s)
{
    string t;
    while(s!=(t=parent[s]))
    {
        cout<<s<<'\n';
        s=t;
    }
}


int bfs(string s,string &f)
{
    if(s.size()<4) return 1;
    map<string,int> visited;
    map<string,string> parent;
    queue<string> q;
    string tmp;
    q.push(s);
    parent[s]=s;
    visited[s]=0;
    int ms=s.size(),pathsize;
    int p[3];
    while(!q.empty())
    {
        tmp=s=q.front();
        q.pop();
        pathsize=visited[s];
        for(int i=0;i<ms;i++)
        {
            for(int j=-1;j<2;j++)
            {
                p[j+1]=(i+ms+j)%ms;
                if(s[p[j+1]]=='0') s[p[j+1]]='1';
                else s[p[j+1]]='0';
            }
            if(visited.find(s)==visited.end())
            {
                parent[s]=tmp;
                if(s==f){
                    print(parent,s);
                    return pathsize+1;
                } 
                q.push(s);
                visited[s]=pathsize+1;
            }
            for(int j=0;j<3;j++)
            {
                if(s[p[j]]=='0') s[p[j]]='1';
                else s[p[j]]='0';
            }
        }
    }
    return 0;
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // for(int i=1;i<15;i++)
    int i=5;
    {
        string s(i,'0'),f(i,'1');
        cout<<i<<"->"<<bfs(s,f)<<'\n';
    }
    
    return 0;

}