#include<bits/stdc++.h>

using namespace std;

map<int,string> moves={{6,"L"},{1,"UL"},{2,"UR"},{3,"R"},{4,"LR"},{5,"LL"}};
int visited[201][201],xi,yi,xf,yf;
int n,ax[]={-2,-2,0,2,2,0},by[]={-1,1,2,1,-1,-2};
map<int,int> rmoves={{1,4},{2,5},{3,6},{4,1},{5,2},{6,3}};

bool validmove(int x,int y)
{
    if(x>=0&&y>=0&&x<n&&y<n) return true;
    return false; 
}

void dfs()
{
    queue<pair<int,int>> q;
    int s,e;
    q.push({xi,yi});
    visited[xi][yi]=-1;
    while(!q.empty())
    {
        tie(s,e)=q.front();
        q.pop();
        for(int i=0;i<6;i++)
        {
            auto g=s+ax[i];
            auto h=e+by[i];
            if(validmove(g,h)&&!visited[g][h])
            {
                q.push({g,h});
                visited[g][h]=i+1;
            }
        }
    }
    stack<string> res;
    int tmp=0;
    if(!visited[xf][yf]) cout<<"Impossible\n";
    else
    {
        while(!(xi==xf&&yi==yf))
        {
            tmp=visited[xf][yf];
            s=rmoves[tmp]-1;
            res.push(moves[tmp]);
            xf=xf+ax[s];
            yf=yf+by[s];
        }
        cout<<res.size()<<'\n';
        while(!res.empty())
        {
            cout<<res.top()<<' ';
            res.pop();
        }
    }
    // cout<<'\n';
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<n;j++) cout<<visited[i][j];
    //     cout<<'\n';
    // }
}

int main(int argc, char const *argv[])
{

    cin>>n>>xi>>yi>>xf>>yf;
    dfs();
    return 0;
}
