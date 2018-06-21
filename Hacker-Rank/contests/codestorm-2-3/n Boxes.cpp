/*
https://www.hackerrank.com/contests/codestorm-2-3/challenges/n-boxes/problem
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n,i,j,k,p,l;
    cin>>n;
    char a[2*n+1][2*n+1];
    p=2*n+1;
     for(j=0;j<p;j++)
     {
         for(k=0;k<p;k++) a[j][k]=' ';
     }
    for(i=1;i<=n;i++)
    {
        l=2*i;
        for(j=0;j<=l;j++)
        {
            for(k=0;k<=l;k++) if(j==0||k==0||j==l||k==l) a[j][k]='*';
        }
    }
     for(j=0;j<p;j++)
     {
         for(k=0;k<p;k++) cout<<a[j][k]<<' ';
         cout<<'\n';
     }
    return 0;
}
