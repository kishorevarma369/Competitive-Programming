#include<bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int n,val;
    cin>>n;
    double ans=0;
    for(int i=0;i<n;i++) cin>>val,ans+=val;
    cout<<fixed<<setprecision(9)<<ans/n;
    return 0;
}
