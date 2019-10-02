//time taken for entire forest to burn

#include<bits/stdc++.h>

using namespace std;
int m,n,c=0;

int t[21][21];

bool isvalid(int x,int y)
{
    if((x>=1&&x<=m)&&(y>=1&&y<=n)) return true;
    return false;
}

int ap[]={1,1,0,-1,-1,-1,0,1};
int bp[]={0,1,1,0,1,-1,-1,-1};

void fcount(int r ,int s)
{
    queue<pair<int,int>> q;
    int op,flag,x,y;
    q.push(make_pair(r,s));
    while(!q.empty())
    {
        op=q.size();
        for(int i=0;i<op;i++)
        {
            tie(x,y)=q.front();
            q.pop();
            t[x][y]=-1;
            for(int p=0;p<8;p++)
            {
                if(isvalid(x+ap[p],y+bp[p])&&t[x+ap[p]][y+bp[p]]==1)
                {
                    t[x+ap[p]][y+bp[p]]=-1;
                    q.push(make_pair(x+ap[p],y+bp[p]));
                }
            }
            
        }
        c++;
    } 
}

int main(int argc, char const *argv[])
{
    int x,y,i,j;
    char ch;
    cin>>m>>n;
    cin>>x>>y;
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            cin>>ch;
            if(ch=='T') t[i][j]=1;
        }
    }
    fcount(x,y);
    cout<<c<<'\n';
    return 0;
}
