#include<bits/stdc++.h>

//time taken 22 min 6 sec and 63 ms

using namespace std;

void reset(int a[])
{
    for(int i=0;i<200;i++) a[i]=0;
}

void reverse(int a[],int s)
{
    int i=0,j=s-1;
    while(i<j)
    {
        swap(a[i],a[j]);
        i++,j--;
    }
}

void multiply (int a[],int b[],int c[])
{
    reset(c);
    reverse(a,100),reverse(b,100);
    int carry=0,i,j,t;
    for(i=0;i<100;i++)
    {
        carry=0;
        for(j=0;j<100;j++)
        {
            t=c[i+j]+a[j]*b[i]+carry;
            c[i+j]=t%10;
            carry=t/10;
        }
        while(carry)
        {
            c[i+j]=carry%10;
            carry/=10;
            j++;
        }
    }
    reverse(c,200);
}

int main()
{
    int a[100]={0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3};
    int b[100]={0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 8};
    int c[200];
    multiply(a,b,c);
    for(int i=200-5;i<200;i++) printf("%d ",c[i]);
    return 0;
}