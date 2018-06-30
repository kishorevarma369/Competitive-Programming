#include<bits/stdc++.h>

using namespace std;


int main(int argc, char const *argv[])
{
    int t,i;
    cin>>t;
    while(t--)
    {
        int n,k,sum1=0,sum2=0;
        cin>>n>>k;
        vector<int> v(n);
        for(i=0;i<n;i++) cin>>v[i];
        sort(v.begin(),v.end());
        if(n-k<k) k=n-k;
        for(i=0;i<k;i++) sum1+=v[i];
        for(;i<n;i++) sum2+=v[i];
        cout<<abs(sum1-sum2)<<'\n';
    }
    return 0;
}
