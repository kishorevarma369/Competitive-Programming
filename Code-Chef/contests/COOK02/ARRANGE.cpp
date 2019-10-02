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
        int n,t,res;
        string s;
        cin>>n>>s;
        int ans=1<<n;
        string fin(ans,' ');
        for(int i=0;i<ans;i++)
        {
            t=i;
            res=0;
            for(int j=0;j<n;j++)
            {
                res=(res<<1)+(t&1);
                t>>=1;
            }
            fin[i]=s[res];
        }
        cout<<fin<<'\n';
    }
    return 0;
}