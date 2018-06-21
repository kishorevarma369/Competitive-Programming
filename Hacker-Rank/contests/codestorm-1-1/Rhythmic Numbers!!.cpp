/*
https://www.hackerrank.com/contests/codestorm-1-1/challenges/rhythmic-numbers
*/
#include<bits/stdc++.h>
using namespace std;


int main()
{
    int a[1000],b[1000],c[1000],i,j=0,cou=2,n,k=0,len;
    a[0]=5;
    b[0]=8;
    for(i=0;cou<=100;i++)
    {
        a[2*i+1]=a[i]*10+4;
        a[2*i+2]=a[i]*10+6;
        b[2*i+1]=b[i]*10+4;
        b[2*i+2]=b[i]*10+6;
        cou+=4;
    }
    len=2*(i-1)+3;
    cin>>n;
    for(i=j=k=0;i<len&&j<len;k++)
    {
        if(a[i]>b[j]) c[k]=b[j++];
        else c[k]=a[i++];
    }
    for(;i<len;i++)
    {
        c[k++]=a[i];
    }
    for(;j<len;j++)
    {
        c[k++]=b[j];
    }
    for(i=0;i<n;i++) cout<<c[i]<<'\n';
    return 0;
}
