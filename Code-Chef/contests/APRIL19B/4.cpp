#include<bits/stdc++.h>

using namespace std;
int maze[10000][10000],sol[10000][10000];
int n;
string originalpath;
void fill(string &s)
{
    int x=0,y=0;
    maze[x][y]=0;
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

void reset()
{
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) maze[i][j]=0,sol[i][j]=0;
}

bool isreachable(int i,int j)
{
    if((isvalid(i,j-1)&&!maze[i][j-1])||(isvalid(i-1,j)&&!maze[i-1][j])) return true;
    return false;
}

void perform()
{
    cin>>n>>originalpath;
    reset();
    fill(originalpath);
    int i,j;
    //fill last row and column
    if(originalpath.back()=='E')
    {
        j=n-1;
        for(i=n-2;i>=0;i--) sol[i][j]=1;
    }
    else
    {
        i=n-1;
        for(j=n-2;j>=0;j--) sol[i][j]=1;
    }
    for(int k=n-2;k>=0;k--)
    {
        i=k;
        for(j=i;j>=0;j--)
        {
            if(isreachable(i,j))
            {
                if(maze[i][j])
                {
                    if(maze[i+1][j]) sol[i][j]=sol[i][j+1];
                    else sol[i][j]=sol[i+1][j];
                }
                else sol[i][j]=sol[i][j+1]+sol[i+1][j];
            }
        }
        j=k;
        for(i=k;i>=0;i--)
        {
            if(isreachable(i,j))
            {
                if(maze[i][j])
                {
                    if(maze[i+1][j]) sol[i][j]=sol[i][j+1];
                    else sol[i][j]=sol[i+1][j];
                }
                else sol[i][j]=sol[i][j+1]+sol[i+1][j];
            }
        }
    }
    if(originalpath[0]=='E') sol[0][1]=0;
    else sol[1][0]=0;
    sol[0][0]=max(sol[0][1],sol[1][0]);
}

void print()
{
    cout<<"-----------------------------------------\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++) cout<<sol[i][j]<<' ';
        cout<<'\n';
    }
    cout<<"-----------------------------------------\n";
}

void printpath()
{
    int x=0,y=0,k=n-1;
    int mymax=sol[x][y];
    // n--;
    while(!(x==k&&y==k))
    {
        if(isvalid(x+1,y))
        {
            if(isvalid(x,y+1))
            {
                if(sol[x][y+1]||sol[x+1][y])
                {
                    if(sol[x][y+1]>=sol[x+1][y])
                    {
                        cout<<"E";
                        y++;
                    }
                    else cout<<"S",x++;
                }
                else break;
            }
            else
            {
                cout<<"S";
                x++;
            }
            
        }
        else
        {
            cout<<"E";
            y++;
        }
    }
    cout<<'\n';
}

int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        perform();
        cout<<"Case #"<<i<<": \n";
        print();
        printpath();
    }
    return 0;
}