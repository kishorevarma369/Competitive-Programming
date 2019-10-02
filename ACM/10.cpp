#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long int ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int>> v(n,vector<int>(n));
        for(auto &row:v) for(auto &col:row) cin>>col;
        bool flag;
        for(int i=0;i<n;i++)
        {
            flag=false;
            for(int j=0;j<n;j++)
            {
                if(v[i][j]==0){ flag=true;break;}
            }
            if(!flag)
            {
                cout<<"NO\n";
                goto dend;
            }
        }
        for(int i=0;i<n;i++)
        {
            flag=false;
            for(int j=0;j<n;j++)
            {
                if(v[j][i]==0){ flag=true;break;}
            }
            if(!flag)
            {
                cout<<"NO\n";
                goto dend;
            }
        }
        cout<<"YES\n";
        dend:
        flag;
    }
    return 0;
}