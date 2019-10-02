#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int ap[]={-1,1,0,0,1,-1,1,-1};
int bp[]={0,0,1,-1,1,-1,-1,1};

bool isvalid(int i,int j)
{
    if(i>=0&&i<8&&j>=0&&j<8) return true;
    return false;
}

void perform()
{
    int i,j,k,m,n;
    cin>>i>>j>>k;
    i--;
    j--;
    int visited[8][8]={0};
    queue<pair<int,int>> q;
    q.push({i,j});
    visited[i][j]=k+1;
    while(!q.empty())
    {
        tie(i,j)=q.front();
        q.pop();
        for(int o=0;o<8;o++)
        {
            m=i+ap[o];
            n=j+bp[o];
            if(isvalid(m,n)&&!visited[m][n])
            {
                visited[m][n]=visited[i][j]-1;
                if(visited[m][n]) q.push({m,n});
            }
        } 
    }
    int cou=0;
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(visited[i][j]) cou++;
        }
    }
    cout<<cou<<'\n';
}

int main(int argc, char const *argv[])
{
    int t;
    cin>>t;
    while(t--)
    {
        perform();
    }
    
    return 0;
}
