#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,val,flag;
        vector<int> a(1001);

        cin>>n>>m;
        for(int i=1;i<=m;i++) cin>>val,a[val]=1;
        flag=2;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==0)
            {
                a[i]=flag;
                if(flag==2) flag=3;
                else flag=2;
            }
        }
        for(int i=1;i<=n;i++) if(a[i]==2) cout<<i<<' ';
        cout<<'\n';
        for(int i=1;i<=n;i++) if(a[i]==3) cout<<i<<' ';
        cout<<'\n';
    }
    return 0;
}