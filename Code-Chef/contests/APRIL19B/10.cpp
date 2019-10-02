#include<bits/stdc++.h>

using namespace std;

// tuple<int,int,int> extgcd(int a,int b)
// {
//     if(b==0) return {1,0,a};
//     int x,y,g;
//     tie(x,y,g)=extgcd(b,a%b);
//     return {y,x-(a/b)*y,g};
// }

vector<pair<int,int>> mystack;
vector<int> status;
int visited[25][25];

int ax[]={1,-1,1,-1};
int ay[]={2,2,-2,-2};
int m,n;

bool isvalid(int x,int y)
{
    if(x>=0&&x<m&&y>=0&&y<n) return true;
    return false;
}

void findsol()
{
    cin>>m>>n;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++) visited[i][j]=0;
    }
    pair<int,int> point={0,0};
    int val=1,uplim=m*n,x,y;
    while(val<=uplim)
    {
        tie(x,y)=point;
        for(int i=0;i<m;i++)
        {
            if(i&1)
            {

            }
            else
            {
                visited[x][y]=val++;
                x++;
                y=(y+2)%n;
            }
            
        }
    }
}

int main()
{
    pair<int,int> point={1,2};
    int x,y;
    tie(x,y)=point;
    x=5;
    cout<<point.first<<point.second;
    return 0;
}