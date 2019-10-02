#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

vector<int> primes;

bool isprime(ll val)
{
    for(auto prime:primes)
    {
        if(prime*prime>val) break;
        if((val%prime)==0) return false;
    }
    return true;
}

void prime_gen()
{
    primes.push_back(2);
    for(int i=3;i<=100001;i+=2)
    {
        if(isprime(i)) primes.push_back(i);
    }
}

ll solve()
{
    ll l,r,ans=0,val;
    cin>>l>>r;
    for(;l<=r;l++)
    {
        val=l;
        if((val%2)==0)
        {
            val/=2;
            if((val%2)==0)
            {
                val/=2;
                if((val%2)==0)
                {
                    val/=2;
                    if(val==1) ans++;
                }
                else if(isprime(val)) ans++;
            }
            else ans++;
        }
        else{
            if(val==1) ans++;
            else if(isprime(val)) ans++;
            // {
            //     vector<pair<int,int>> prime_factors;
            //     int t_ans=1;
            //     for(auto prime:primes)
            //     {
            //         if(prime*prime>val)
            //         {
            //             prime_factors.push_back({val,1});
            //             break;
            //         }
            //         if((val%prime)==0)
            //         {
            //             prime_factors.push_back({prime,1});     
            //             val/=prime;
            //             while((val%prime)==0)    
            //             {
            //                 prime_factors.back().second++;
            //                 val/=prime;
            //             } 
            //             t_ans*=prime_factors.back().second+1;           
            //         }
            //         if(t_ans>2) break;
            //     }
            //     if(t_ans<=2) ans++;
            // }
        }
    }
    return ans;
}

int main()
{
    prime_gen();
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cout<<"Case #"<<i<<": "<<solve()<<'\n';
    }
    return 0;
}