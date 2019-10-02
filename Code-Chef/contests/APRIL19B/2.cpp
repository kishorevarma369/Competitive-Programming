#include<bits/stdc++.h>

using namespace std;
vector<vector<int>> maze;
int n;
void fill(string s)
{
    int x=0,y=0;
    maze[x][y]=1;
    for(auto dir:s)
    {
        if(dir=='E')
        {
            maze[x][y+1]=1,y++;
        }
        else maze[x+1][y]=1,x++;
    }
}


bool isvalid(int x,int y)
{
    if(x>=0&&x<n&&y>=0&&y<n) return true;
    return false;
}

void perform()
{
    string s;
    cin>>n>>s;
    maze.resize(n,vector<int>(n));
    fill(s);
    queue<pair<int,int>> myqueue;
    string solution;
    solution.reserve(s.size());
    myqueue.push({0,0});
    while(solution.size()!=s.size())
    {
        auto pos=myqueue.back();
        if(isvalid(pos.first+1,pos.second))
        {
            
        }
    }
}

int main()
{
    int t;
    cin>>t;
    string s;
    for(int i=1;i<=t;i++)
    {
        cout<<"Case #"<<i<<": ";
        perform();
    }
    return 0;
}