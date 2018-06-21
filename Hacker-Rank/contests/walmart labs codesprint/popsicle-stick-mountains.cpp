#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

unsigned long long int catalan[2001],con=(unsigned long long int)1e9+7;

void catalanDP(unsigned int n=2000)
{
    catalan[0] = catalan[1] = 1;
    for (int i=2; i<=n; i++)
    {
        catalan[i] = 0;
        for (int j=0; j<i; j++)
        {
          catalan[i] = ( catalan[i]%con + (catalan[j] * catalan[i-j-1])%con ) %con;
        }
    }
    for(int i=2;i<=n;i++)
    {
      catalan[i]=(catalan[i]+catalan[i-1])%con;
    }
}



int main()
{
    int i,n;
    cin>>n;
    catalanDP();
    while(n--)
    {
      cin>>i;
      cout<<catalan[i/2]<<'\n';
    }
    return 0;
}
