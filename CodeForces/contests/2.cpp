#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long int ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m,ans=0,mlevel=0,filled=0,need_to_fill=0;
    cin>>n>>m;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
        ans+=v[i];
    } 
    sort(v.begin(),v.end());
    for(auto &val:v)
    {
        if(val>mlevel)
        {
            need_to_fill+=val-mlevel-1;
            filled++;
            mlevel=val;
        }
        else
        {
            filled++;
            if(need_to_fill>0) need_to_fill--;
        }
    }
    cout<<(ans-(filled+need_to_fill));
    return 0;
}