#include<bits/stdc++.h>

using namespace std;

int grid[3][3];

void toggle(int i, int j,int val)
{
    if(val&1) val=1;
    else return;
    grid[i][j]^=val;
    if(j+1<3) grid[i][j+1]^=val;
    if(j-1>=0)grid[i][j-1]^=val;
    if(i-1>=0)grid[i-1][j]^=val;
    if(i+1<3)grid[i+1][j]^=val;
}

int main()
{
    int val;
    for(int i=0;i<3;i++) for(int j=0;j<3;j++) grid[i][j]=1;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>val;
            toggle(i,j,val);
        }
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++) cout<<grid[i][j];
        cout<<'\n';
    }
    return 0;
}