#include<bits/stdc++.h>

using namespace std;
// #define debug

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t,n,val,ans,ans1,ans2;
    cin>>t;
    // 10 5 7
    // 6 12 18 16
    while(t--)
    {
        cin>>n;
        ans=0;
        map<int,int> m;
        for(int i=0;i<n;i++){
            cin>>val;
            m[val]++;
        }
        auto last_elm=m.end();
        last_elm--;
        if(last_elm->second==n)
        {
            cout<<(2*last_elm->first)<<'\n';
            continue;
        }
        else{
            int arr[2];
            arr[0]=last_elm->first;
            last_elm=m.erase(last_elm);
            assert(last_elm==m.end());
            last_elm--;
            arr[1]=last_elm->first;
            last_elm=m.erase(last_elm);
            int g,elm;
            if(m.size()){
                g=m.begin()->first;
                for(auto &pr:m)
                {
                    elm=pr.first;
                    g=__gcd(g,elm);
                    if(g==1) break;
                }
            }
            else{
                cout<<(arr[0]+arr[1])<<'\n';
                continue;
            }
            ans1=arr[0]+__gcd(arr[1],g);
            ans2=arr[1]+__gcd(arr[0],g);
            ans=max(ans1,ans2);
            cout<<ans<<'\n';
        }
    }
    return 0;
}