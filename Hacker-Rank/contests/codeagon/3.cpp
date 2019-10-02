#include<bits/stdc++.h>
using namespace std;

bool prime[32000];

#define mycon 1000000000

bool is_prime(int n)
{
  if(n<32000) return prime[n];
  if(n%2==0) return 0;
  for(int i=3;i*i<=n;i+=2)
  {
      if(prime[i]&&n%i==0) return 0; 
  }
  return 1;
}

void primegen()
{
    prime[2]=1;
    for(int i=3;i<32000;i+=2) prime[i]=1;
    for(int i=3;i<32000;i+=2)
    {
        if(prime[i])
        {
            for(int j=2*i;j<32000;j+=i) prime[j]=0;
        }
    }
}

void gen(int l,int r,vector<int> &myprimes)
{
    for(;l<=r;l++)
    {
        if(is_prime(l)) myprimes.push_back(l);
    }
}

int main()
{
	int t;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    primegen();
	cin>>t;
	while(t--)
	{
		int l,r,n,p,j,i;
        cin>>l>>r>>n;
        vector<int> myprimes;
        gen(l,r,myprimes);
        for(i=0;i<n;i++)
        {
            cin>>p;
            if(p<l) p=l;
            if(p>r)
            {
                cout<<"-1\n";
                continue;
            }
            
            auto it=lower_bound(myprimes.begin(),myprimes.end(),p);
            if(it==myprimes.end())
            {
                cout<<"-1\n";
                continue;
            }
            cout<<*it<<'\n';
        }
	}
	return 0;
}
