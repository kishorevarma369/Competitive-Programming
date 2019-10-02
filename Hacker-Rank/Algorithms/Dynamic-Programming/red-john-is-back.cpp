#include<bits/stdc++.h>

using namespace std;

int ans[41];
vector<int> primes;

void pre()
{
    for(int i=0;i<4;i++) ans[i]=1;
    for(int i=4;i<41;i++) ans[i]=ans[i-1]+ans[i-4];
}

void primegen()
{
    primes.push_back(2);
    bool prime;
    for(int i=3;i<300000;i+=2)
    {
        prime=true;
        for(int j=0;j<primes.size()&&primes[j]*primes[j]<=i;j++)
        {
            if(i%primes[j]==0)
            {
                prime=false;
                break;
            } 
        }
        if(prime) primes.push_back(i);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    primegen();
    int t,n;
    cin>>t;
    cout<<"ans"<<'\n';
    while(t--)
    {
        cin>>n;
        if(ans[n]==1) cout<<"0\n";
        else
        {
            auto it=upper_bound(primes.begin(),primes.end(),ans[n]);
            cout<<int(it-primes.begin())<<'\n';
        }
        
    }
    return 0;
}