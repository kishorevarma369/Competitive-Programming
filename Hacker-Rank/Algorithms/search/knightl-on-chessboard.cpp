#include<bits/stdc++.h>

using namespace std;

int n;

bool isvalid(int i,int j)
{
    if((i>=0&i<n)&&(j>=0&&j<n)) return true;
    return false;
}

int e[]={1,1,-1,-1};
int f[]={1,-1,1,-1};

void findMinSteps(int p,int q)
{
    vector<vector<int>> v(n,vector<int>(n,INT_MAX));
    v[0][0]=0;
    queue<pair<int,int>> qu;
    int i=0,j=0,x,y;
    qu.push(make_pair(i,j));
    while(!qu.empty())
    {
        tie(i,j)=qu.front();
        qu.pop();
        for(int o=0;o<4;o++)
        {
            x=i+e[o]*p;
            y=j+f[o]*q;
            if(isvalid(x,y)&&(v[i][j]+1<v[x][y])){
                v[x][y]=v[i][j]+1;
                qu.push(make_pair(x,y)); 
            } 
        }
        for(int o=0;o<4;o++)
        {
            x=i+e[o]*q;
            y=j+f[o]*p;
            if(isvalid(x,y)&&(v[i][j]+1<v[x][y])){
                v[x][y]=v[i][j]+1;
                qu.push(make_pair(x,y)); 
            } 
        }
    }
    #ifdef test
    for(auto &i:v)
    {
        for(auto &j:i){
            if(j!=INT_MAX) cout<<j<<' ';
            else cout<<"-1 ";
        }
        cout<<'\n';
    }
    #else

    if(v[n-1][n-1]==INT_MAX) cout<<"-1 ";
    else cout<<v[n-1][n-1]<<' ';
    
    #endif
}

int main()
{
    int i,j;
    cin>>n;
    //findMinSteps(1,3);
    for(i=1;i<n;i++)
    {
        for(j=1;j<n;j++) findMinSteps(i,j);
        cout<<'\n';
    }
    return 0;
}