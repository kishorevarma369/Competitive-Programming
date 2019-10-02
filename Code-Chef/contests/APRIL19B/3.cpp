#include<bits/stdc++.h>

using namespace std;
vector<vector<int>> maze;
int n,sn;
string solution;
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

bool findsol(int x,int y)
{
    if(!(x>=0&&x<n&&y>=0&&y<n)) return false;
    if(solution.size()==sn)
    {
        cout<<solution<<'\n';
        return true;
    }
    if(maze[x][y])
    {
        if(isvalid(x,y+1))
        {
            if(maze[x][y+1])
            {
                if(isvalid(x+1,y))
                {
                    solution.push_back('S');
                    if(findsol(x+1,y)) return true;
                    solution.pop_back();
                }
            }
        }
        if(isvalid(x+1,y))
        {
            if(maze[x+1][y])
            {
                if(isvalid(x,y+1))
                {
                    solution.push_back('E');
                    if(findsol(x,y+1)) return true;
                    solution.pop_back();
                }
            }
        }
    }
    else
    {
        solution.push_back('E');
        if(findsol(x,y+1)) return true;
        solution.pop_back();
        solution.push_back('S');
        if(findsol(x+1,y)) return true;
        solution.pop_back();
    }
}

void perform()
{
    string s;
    cin>>n>>s;
    sn=2*n-2;
    maze.resize(n,vector<int>(n));
    fill(s);
    solution.clear();
    solution.reserve(sn);
    findsol(0,0);
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