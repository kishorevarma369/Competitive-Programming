#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

bool prime[1000001];

void prime_gen()
{
    prime[2]=true;
    for(int i=3;i<1000000;i+=2) prime[i]=true;
    for(int i=3;i<1000000;i+=2)
    {
        if(prime[i])
        {
            for(int j=i+i;j<1000000;j+=i) prime[j]=false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    prime_gen();
    int t,n,val,x;
    cin>>t;
    while(t--)
    {
        cin>>n;
        map<int,int> m;
        int maxsize=0,ans=0;
        for(int i=0;i<n;i++){ 
            cin>>val;
            if(val==1)
            {
                ans++;
                continue;
            }
            if(!prime[val]){
                m.clear();
                ans=0;
                continue;
            }
            x=m[val]++;
            if(x)
            {
                m.clear();
                m[val]++;
                ans=0;
            }
            ans++;
            if(ans>maxsize) maxsize=ans;
        }
        if(ans>maxsize) maxsize=ans;
        if(maxsize<2) cout<<"-1\n";
        else cout<<maxsize<<'\n';
    }
    return 0;

}