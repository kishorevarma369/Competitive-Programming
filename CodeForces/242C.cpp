#include<bits/stdc++.h>

using namespace std;

int xi,yi,xf,yf;
int ap[]={1,1,0,-1,-1,-1,0,1};
int bp[]={0,1,1,0,1,-1,-1,-1};

map<int,vector<pair<int,int>>> rows;

void process()
{
    for(auto &row:rows)
    {
        auto &r=row.second;
        vector<pair<int,int>> res;
        sort(r.begin(),r.end());
        res.push_back(r[0]);
        for(int i=1;i<r.size();i++)
        {
            auto &p=res.back();
            if(r[i].first<=p.second+1) p.second=max(p.second,r[i].second);
            else res.push_back(r[i]);
        }
        row.second=res;
    }
}

bool valid(int b,int e)
{
    auto &row=rows[b];
    for(auto &point:row)
    {
        if(e>=point.first)
        {
            if(e<=point.second)  return true;
        }
        else break;
    }
    return false;
}

int main()
{
    cin>>xi>>yi>>xf>>yf;
    int n,r,b,e;
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>r>>b>>e;
        rows[r].push_back(make_pair(b,e));
    }
    process(); 
    queue<pair<int,int>> q;
    q.push(make_pair(xi,yi));
    map<pair<int,int>,int> visited;
    visited[make_pair(xi,yi)]=0;
    int score;
    while(!q.empty())
    {
        tie(xi,yi)=q.front();
        score=visited[q.front()];
        q.pop();
        for(int i=0;i<8;i++)
        {
            if(valid(xi+ap[i],yi+bp[i]))
            {
                auto tmp=make_pair(xi+ap[i],yi+bp[i]);
                if(visited.find(tmp)!=visited.end()) continue;
                q.push(tmp);
                visited[tmp]=score+1;
                if(xi+ap[i]==xf&&yi+bp[i]==yf) goto finished;
            }
        }
    }
    cout<<"-1\n";
    return 0;
    finished:
    cout<<score+1<<'\n';
    return 0;
}