#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,a[3]={0},b[3];
    cin>>n;
    while(n--)
    {
        for(int i=0;i<3;i++) cin>>b[i],a[i]+=b[i];
    }
    for(int i=0;i<3;i++) if(a[i]) goto finals;
    cout<<"YES\n";
    return 0;
    finals:
    cout<<"NO\n";
    return 0;
}