#include<bits/stdc++.h>

using namespace std;

#define size 1002

int maze[size][size];
int n,sn,spos;
char solution[2*size];

void fill(string s)
{
    int x=0,y=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++) maze[i][j]=0;
    }
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
    if(spos==sn)
    {
        solution[spos]=0;
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
                    solution[spos++]='S';
                    if(findsol(x+1,y)) return true;
                    spos--;
                }
            }
        }
        if(isvalid(x+1,y))
        {
            if(maze[x+1][y])
            {
                if(isvalid(x,y+1))
                {
                    solution[spos++]='E';
                    if(findsol(x,y+1)) return true;
                    spos--;
                }
            }
        }
    }
    else
    {
        solution[spos++]='E';
        if(findsol(x,y+1)) return true;
        solution[spos-1]='S';
        if(findsol(x+1,y)) return true;
        spos--;
    }
    return false;
}

void perform()
{
    string s;
    cin>>n>>s;
    sn=2*n-2;
    fill(s);
    spos=0;
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