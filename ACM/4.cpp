#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long int ll;

#define mymod 1000000007ULL

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        ll n,k,i=0,pro=1,m,r;
        cin>>n>>k;
        pro=(k*(k+1))/2;
        if(n<pro) cout<<"-1\n";
        else if(pro==n) cout<<"0\n";
        else{
            i=k;
            vector<int> v(k);
            for(auto &p:v) p=i--;
            int res=n-pro;
            int add=res/k;
            r=res%k;
            for(i=0;i<k;i++)
            {
              c[i]=c[i]+add;
            }
            for(i=0;i<rem;i++)
            {
              c[i]=c[i]+1;
            }
            
            
        }
        
    }
    return 0;
}