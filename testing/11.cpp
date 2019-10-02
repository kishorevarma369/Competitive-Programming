#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main()
{
    ll a,b,m,ans=1,t;
    cin>>a>>b>>m;
    t=(a/m)*m;
    if(a%m==0||t>b) cout<<"0"<<endl;
    else{
        for(ll i=a;i>b;i--) ans=(ans*(i%m))%m;
        cout<<ans<<endl;
    }
    return 0;
}