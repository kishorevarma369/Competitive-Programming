#include<bits/stdc++.h>

//time taken 22 min 6 sec and 63 ms

using namespace std;


int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int ans=0;
        for(;n>0;n>>=1)
        {
            ans++;
        }
        cout<<ans<<'\n';
    }
    return 0;
}