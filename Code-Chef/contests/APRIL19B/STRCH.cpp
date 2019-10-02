#include<bits/stdc++.h>

using namespace std;
//time taken 16 minutes 36 sec and 10 milli seconds
void solve()
{
    int n;
    string s;
    char ch;
    cin>>n>>s>>ch;
    int validpos=n;
    long long int ans=0;
    for(int i=n-1;i>=0;i--)
    {
        if(s[i]==ch)
        {
            ans+=n-i;
            validpos=i;
        }
        else
        {
            ans+=n-validpos;
        }
    }
    cout<<ans<<'\n';
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}