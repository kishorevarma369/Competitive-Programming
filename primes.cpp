#include<bits/stdc++.h>

using namespace std;

auto gen_primes_lt(int n)
{
    vector<int> primes;
    bool prime;
    primes.push_back(2);
    for(int i=3;i<n;i+=2)
    {
        prime=true;
        for(int j=0;j<primes.size()&&primes[j]*primes[j]<=i;j++)
        {
            if(i%primes[j]==0) {
                prime=false;
                break;
            }
        }
        if(prime)
        {
            if(primes.back()*i>1000000000) return primes;
            primes.push_back(i);
        } 
    }
    return primes;
}

int main()
{
    auto primes=gen_primes_lt(7368788);
    cout<<primes.size()<<endl;
    cout<<primes[primes.size()-1]<<' '<<primes[primes.size()-2];
    return 0;
}