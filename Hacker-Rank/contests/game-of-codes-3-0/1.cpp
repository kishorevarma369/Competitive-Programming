#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//https://www.hackerrank.com/contests/game-of-codes-3-0/challenges/help-dory/
int nearest_power_2(int n)
{
    int c=0;
    while(n)
    {
        c++;
        n>>=1;
    }
    return 1<<(c-1);
}

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        n-=nearest_power_2(n);
        cout<<(2*n+1)<<'\n';
    }
    
    return 0;
}
