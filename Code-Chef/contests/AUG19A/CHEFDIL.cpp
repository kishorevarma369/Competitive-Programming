#include<bits/stdc++.h>

using namespace std;

#define fast_io() (cin.tie(NULL),ios_base::sync_with_stdio(false))

int main()
{
    fast_io();
    int t,ones;
    cin>>t;
    string s;
    while(t--)
    {
        cin>>s;
        ones=0;
        for(auto &ch:s) if(ch=='1') ones++;
        if(ones&1) cout<<"WIN\n";
        else cout<<"LOSE\n";
    }    
    return 0;
}