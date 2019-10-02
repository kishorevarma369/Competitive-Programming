#include<bits/stdc++.h>

using namespace std;

// tuple<int,int,int> extgcd(int a,int b)
// {
//     if(b==0) return {1,0,a};
//     int x,y,g;
//     tie(x,y,g)=extgcd(b,a%b);
//     return {y,x-(a/b)*y,g};
// }

int visited[25][25];

int m,n;

void findsol()
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++) visited[i][j]=0;
    }
    bool transpose=false;
    if(m>n){ transpose=true;swap(m,n);}
    pair<int,int> point=make_pair(0,0);
    int val=1,uplim=m*n,x,y;
    if(m==2)
    {
        if(n<5)
        {
            cout<<"IMPOSSIBLE\n";
            return;   
        }
        point.first=1;
        point.second=2;
        for(int i=0;i<n;i++)
        {
            tie(x,y)=point;
            visited[x][y]=val++;
            y=(y-2+n)%n;
            x--;
            visited[x][y]=val++;
            point.second=(point.second+1)%n;
        }
    }
    else
    {
        while(val<=uplim)
        {
            tie(x,y)=point;
            for(int i=0;i<m;i++)
            {
                if(i&1)
                {
                    visited[x][y]=val++;
                    x++;
                    y=(y-2+n)%n;
                }
                else
                {
                    visited[x][y]=val++;
                    x++;
                    y=(y+2)%n;
                }
            }
            point.second++;
        }
    }
    if(transpose)
    {
        vector<vector<int>> v(n,vector<int>(m));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++) v[j][i]=visited[i][j];
        }
        swap(m,n);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++) visited[i][j]=v[i][j];
        }
    }
    // for(int i=0;i<m;i++)
    // {
    //     for(int j=0;j<n;j++) cout<<visited[i][j]<<' ';
    //     cout<<'\n';
    // }
    map<int,pair<int,int>> mymap;
    cout<<"POSSIBLE\n";
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++) mymap[visited[i][j]]=make_pair(i+1,j+1);
    }
    for(auto &elm:mymap)
    {
        cout<<elm.second.first<<' '<<elm.second.second<<'\n';
    }
}

int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>m>>n;
        printf("Case #%d: ",i);
        if((m!=1&&n!=1)&&(m>3||n>3)) {
            
            findsol();
        }
        else cout<<"IMPOSSIBLE\n";
    }
    return 0;
}