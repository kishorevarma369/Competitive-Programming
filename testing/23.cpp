#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long int ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t,n,val;
    cin>>t;
    while(t--)
    {
        cin>>n;
        vector<ll> occourences(n+1,0);
        map<ll,ll> freq;
        for(int i=0;i<n;i++){
            cin>>val;
            t=freq[val]++;
            occourences[t]++;
        }
        ll cou=0;
        for(int i=0;i<n;i++)
        {
            if(occourences[i]) cou++;
            else break;
        }
        cout<<cou<<'\n';
    }
    return 0;
}