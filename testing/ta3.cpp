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
    // ones.push_back(0);
    // twos.push_back(0);
    sort(ones.begin(),ones.end(),greater<ll>());
    sort(twos.begin(),twos.end(),greater<ll>());
    ll ans0=0,ans1=0,ans2=0;
    pair<int,int> pos0(0,0),pos1,pos2;
    // vector<ll> ans(total_weight+1);
    // vector<pair<int,int>> pos(total_weight+1);
    if(total_weight>=1)
    {
        if(0<ones.size()){
            ans1=ones[0];
            pos1={1,0};
        }
        else
        {
            ans1=0;
            pos1={0,0};
        }
        cout<<ans1<<' ';
    }
    int x1,y1,x2,y2;
    for(ll i=2;i<=total_weight;i++)
    {
        tie(x1,y1)=pos1;
        if(x1<ones.size()) ans2=ans1+ones[x1++];
        else ans2=ans1;
        tie(x2,y2)=pos0;
        if(y2<twos.size()&&ans2<ans0+twos[y2])
        {
            ans2=ans0+twos[y2];
            y2++;
            pos2={x2,y2};
        }
        else
        {
            pos2={x1,y1};
        }
        cout<<ans2<<' ';
        ans0=ans1;ans1=ans2;
        pos0=pos1;pos1=pos2;
    }
    return 0;
}