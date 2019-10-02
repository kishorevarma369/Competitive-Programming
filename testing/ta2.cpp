#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n,weight,value,total_weight=0;
    vector<ll> ones;
    vector<ll> twos;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>weight>>value;
        if(weight==2) twos.push_back(value);
        else ones.push_back(value);
        total_weight+=weight;
    }
    ones.push_back(0);
    twos.push_back(0);
    sort(ones.begin(),ones.end(),greater<ll>());
    sort(twos.begin(),twos.end(),greater<ll>());
    vector<ll> ans(total_weight+1);
    vector<pair<int,int>> pos(total_weight+1);
    if(total_weight>=1)
    {
        ans[1]=ones[0];
        pos[1]={1,0};
        cout<<ans[1]<<' '; 
    }
    int x1,y1,x2,y2;
    for(ll i=2;i<=total_weight;i++)
    {
        tie(x1,y1)=pos[i-1];
        ans[i]=ans[i-1]+ones[x1];
        x1++;
        tie(x2,y2)=pos[i-2];
        if(ans[i]<ans[i-2]+twos[y2])
        {
            ans[i]=ans[i-2]+twos[y2];
            y2++;
            pos[i]={x2,y2};
        }
        else
        {
            pos[i]={x1,y1};
        }
        cout<<ans[i]<<' ';
    }
    return 0;
}