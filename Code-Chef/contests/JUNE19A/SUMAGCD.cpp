#include<bits/stdc++.h>

using namespace std;

int arr[100005];

// #define debug

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t,n,val,ans;
    srand(time(NULL));
    #ifndef debug
    cin>>t;
    #else
    t=5;
    #endif
    while(t--)
    {
        #ifndef debug
            cin>>n;
        #else
            n=5;
        #endif
        ans=0;
        map<int,int> m;
        for(int i=0;i<n;i++){
            #ifndef debug
            cin>>val;
            #else
            val=rand()%5+2;
            cout<<val<<' ';
            #endif
            m[val]++;
        }
        #ifdef debug
            cout<<'\n';
        #endif
        auto last_elm=m.end();
        last_elm--;
        if(last_elm->second==n)
        {
            cout<<(2*last_elm->first)<<'\n';
            continue;
        }
        else{
            ans=last_elm->first;
            m.erase(last_elm);
            int g=m.begin()->first,elm;
            for(auto &pr:m)
            {
                elm=pr.first;
                g=__gcd(g,elm);
                if(g==1) break;
            }
            cout<<(ans+g)<<'\n';
        }
    }
    return 0;
}