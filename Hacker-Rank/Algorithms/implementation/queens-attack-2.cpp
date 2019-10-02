#include <bits/stdc++.h>

using namespace std;

char *v[100001];
int n,k,qx,qy,ans=0;


void initialize()
{
    int x,y;
    cin>>qx>>qy;
    //v[qx][qy]=2;
    for(int i=1;i<=n;i++)
    {
        v[i]=(char*)malloc(n+1);
        if(v[i]==NULL)
        {
            cout<<i<<'\n';
            system("pause");
        }
    } 
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++) v[i][j]=1;
    }
    //cout<<"done";
    for(int i=0;i<k;i++)
    {
        cin>>x>>y;
        v[x][y]=0;
    }
}

void calculate()
{
    int i,j;
    for(i=qx+1;i<=n&&v[i][qy];i++) ans++;
    for(i=qy+1;i<=n&&v[qx][i];i++) ans++;
    for(i=qx-1;i>0&&v[i][qy];i--) ans++;
    for(i=qy-1;i>0&&v[qx][i];i--) ans++;
    
    for(i=qx+1,j=qy+1;i<=n&&j<=n&&v[i][j];i++,j++) ans++;
    
    for(i=qx-1,j=qy-1;i>0&&j>0&&v[i][j];i--,j--) ans++;
    
    for(i=qx-1,j=qy+1;i>0&&j<=n&&v[i][j];i--,j++) ans++;
    
    for(i=qx+1,j=qy-1;i<=n&&j>0&&v[i][j];i++,j--) ans++;
    
    cout<<ans<<'\n';
}

int main()
{
    cin>>n>>k;
    initialize();
    calculate();
    return 0;
}
