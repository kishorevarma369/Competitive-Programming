#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main(int argc, char const *argv[])
{
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        if(n&1&&m&1) cout<<"NO\n";
        else cout<<"YES\n";
    }
    return 0;
}
