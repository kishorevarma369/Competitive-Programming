#include<bits/stdc++.h>

using namespace std;

#define fast_io() (cin.tie(NULL),ios_base::sync_with_stdio(false))

int arr[100005];

void solve()
{
    int n;
    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        cin>>arr[i];
        arr[i]^=arr[i-1];
        cout<<arr[i]<<' ';
    }
    cout<<'\n';
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            for(int k=j;k<=n;k++)
            {
                if((arr[i-1]^arr[j-1])==(arr[j-1]^arr[k]))
                {
                cout<<(arr[i-1]^arr[j-1])<<" "<<(arr[j-1]^arr[k])<<"->";
                // cout<<arr[i-1]<<" "<<arr[j-1]<<' '<<arr[k]<<'\n';
                cout<<i-1<<" "<<j-1<<' '<<k<<'\n';
                    ans++;
                }
            }
        }
    }
    cout<<ans<<'\n';
}

int main()
{
    fast_io();
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }    
    return 0;
}