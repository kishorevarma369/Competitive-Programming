#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    long long int a,b,n,i;
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n&1)
        {
            a=1,b=2,i=3;
        }
        else
        {
            a=1,b=4,i=4;
        }
        for(;i<=n;i+=2) a+=b,b<<=2;
        cout<<a<<' '<<b<<' ';
    }
    
    return 0;
}