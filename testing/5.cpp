#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,r,val;
    cin>>n>>r;
    while(n--)
    {
        cin>>val;
        if(val>=r) cout<<"Good boi\n";
        else cout<<"Bad boi\n";
    }
    return 0;
}