#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int calculate(ll a[3][2])
{
    ll d[3]={0};
    d[0]=(a[0][0]-a[1][0])*(a[0][0]-a[1][0])+(a[0][1]-a[1][1])*(a[0][1]-a[1][1]);
    d[1]=(a[1][0]-a[2][0])*(a[1][0]-a[2][0])+(a[1][1]-a[2][1])*(a[1][1]-a[2][1]);
    d[2]=(a[0][0]-a[2][0])*(a[0][0]-a[2][0])+(a[0][1]-a[2][1])*(a[0][1]-a[2][1]);
    sort(d,d+3);
    if((d[0]+d[1])==d[2]) return 1;
    return 0;
}

int main(int argc, char const *argv[])
{
    ll t;
    cin>>t;
    ll c=0;
    while(t--)
    {
        ll p[3][2];
        for(int i=0;i<3;i++) cin>>p[i][0]>>p[i][1];
        if(calculate(p)) c++;
    }
    cout<<c<<'\n';
    return 0;
}
