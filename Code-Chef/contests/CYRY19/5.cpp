#include<bits/stdc++.h>

using namespace std;

#define INF 12345

int main()
{
    int n,e1,e2;
    cin>>n;
    vector<vector<int>> v(n,vector<int>(n,INF));
    for(int i=0;i<n;i++) v[i][i]=0;
    for(int i=1;i<n;i++)
    {
        cin>>e1>>e2;
        e1--,e2--;
        v[e1][e2]=v[e2][e1]=1;
    }
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(v[i][j]>v[i][k]+v[k][j]) v[i][j]=v[i][k]+v[k][j];
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++) cout<<v[i][j]<<' ';
        cout<<'\n';
    }
    vector<int> cost(n);
    for(auto &i:cost) cin>>i;
    vector<int> ans(n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++) ans[i]+=v[i][j]*cost[j];
    }
    int t;
    cin>>t;
    while(t--)
    {
        cin>>e1>>e2;
        e1--,e2--;
        //cout<<ans[e1]<<' '<<ans[e2]<<'\n';
        if(ans[e1]==ans[e2]) cout<<"Both\n";
        else if(ans[e1]>ans[e2]) cout<<"Debasish\n";
        else cout<<"Amit\n";
    }
    cout.flush();
    return 0;
}