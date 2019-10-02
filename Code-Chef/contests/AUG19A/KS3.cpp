#include<bits/stdc++.h>

using namespace std;

#define fast_io() (cin.tie(NULL),ios_base::sync_with_stdio(false))
int arr[100005];
void solve()
{
    int n,prev=0;
    cin>>n;
    map<int,vector<int>> m;
    m[0].push_back(0);
    arr[0]=0;
    for (int i = 1; i <= n; i++)
    {
        cin>>arr[i];
        // arr[i]=rand()%1000000;
        // arr[i]=5555;
        arr[i]^=arr[i-1];
        m[arr[i]].push_back(i);
    }
    long long int ans=0,k,tans;
    for(auto &pr:m)
    {
        auto &v=pr.second;
        k=v.size();
        tans=0;
        for(int i=0;i<k;i++)
        {
            tans+=(2ll*(i+1)-k-1)*v[i];
        }
        tans=tans-(1ll*k*(k-1))/2;
        ans+=tans;
    }
    cout<<ans<<'\n';
}

int main()
{
    srand(time(NULL));
    fast_io();
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }    
    return 0;
}