#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n],i,val=1;
    if(n&1)
    {
        cout<<"-1\n";
        return 0;
    }
    for(i=1;i<=n;i+=2)
    {
        cout<<i+1<<' '<<i<<' ';
    }
    return 0;
}