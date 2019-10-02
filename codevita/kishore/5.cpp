#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main()
{
    int n;
    cin>>n;
    double x,y,speed;
    map<double,int> m;
    for(int i=0;i<n;i++)
    {
        cin>>x>>y>>speed;
        double time_taken=sqrt(x*x+y*y)/speed;
        m[time_taken]++;
    }
    ll ans=0;
    for(auto pr:m)
    {
        ans+=((ll)pr.second*(pr.second-1))/2;
    }
    cout<<ans<<'\n';
    return 0;
}