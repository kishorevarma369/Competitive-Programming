#include<bits/stdc++.h>

using namespace std;

int main()
{
    int m,n;
    int prime[55]={0};
    for(int i=3;i<55;i+=2) prime[i]=1;
    for(int i=3;i<55;i++)
    {
        if(prime[i])
        {
            for(int j=i+i;j<55;j+=i) prime[j]=0;
        }
    }
    cin>>n>>m;
    int i;
    for(i=n+1;i<m;i++)
    {
        if(prime[i]) break;
    }
    if(i==m&&prime[i]) cout<<"YES\n";
    else cout<<"NO\n";
    return 0;
}