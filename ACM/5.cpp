#include<bits/stdc++.h>
using namespace std;
unsigned long long int ans(int c[],int n,long long int m)
{
    unsigned long long int prod=1,i;
          for(i=0;i<n;i++)
            {
             unsigned long long int p=1ull*c[i]*c[i];
             unsigned long long int q=(p-c[i])%m;
             prod=((prod%m)*(q%m))%m;
             
            }
        return prod;
}
int main()
{
    int t;cin>>t;
    long m=1000000007;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int c[k],i;
        int k1=k;
        for(i=0;i<k;i++)
        {
            c[i]=k1;
            k1--;
        }
        int sig=(k*(k+1))/2;
        if(sig>n)
        {
            cout<<"-1"<<endl;
        }
        else if(sig==n) cout<<"0"<<endl;
        else
        {
            
            int res=n-sig;
            int add=res/k;
            int rem=res%k;
            for(i=0;i<k;i++)
            {
              c[i]=c[i]+add;
            }
            for(i=0;i<rem;i++)
            {
              c[i]=c[i]+1;
            }
            cout<<ans(c,k,m)%m<<endl;
        }
        
    }
}