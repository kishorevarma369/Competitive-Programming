#include<bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,aval,ans1=0,ans2=0;
        cin>>n;
        vector<int> a(n);
        for(auto &val:a) cin>>val;
        for(int i=1;i<n;i++) 
        {
            if(i&1) ans1+=abs(a[i]-1);
            else ans1+=abs(1-a[i-1]);
        }
        // cout<<ans1<<'\n';
        for(int i=1;i<n;i++) 
        {
            if(i&1) ans2+=abs(1-a[i-1]);
            else ans2+=abs(a[i]-1);
        }
        // cout<<ans2<<'\n';
        cout<<max(ans1,ans2)<<'\n';
    }
    return 0;
}
