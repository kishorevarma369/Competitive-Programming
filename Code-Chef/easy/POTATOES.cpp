#include<bits/stdc++.h>

using namespace std;

vector<int> prime;

void generatePrimes()
{
    int i,j,f;
    prime.push_back(2);
    for(i=3;i<2500;i+=2)
    {
        f=1;
        for(j=0;j<prime.size()&&prime[j]*prime[j]<=i;j++)
        {
            if(i%prime[j]==0)
            {
                f=0;
                break;
            } 
        }
        if(f) prime.push_back(i);
    }
}


int main(int argc, char const *argv[])
{
    generatePrimes();
    int t,i,j,k;
    cin>>t;
    while(t--)
    {
        cin>>i>>j;
        k=*upper_bound(prime.begin(),prime.end(),i+j);
        cout<<k-i-j<<'\n';
    }
    return 0;
}
