#include<bits/stdc++.h>

using namespace std;

#define uplim 50005

int a[2][uplim],n,arr[10];

int getval(int x,int y,int z)
{
    return arr[x-1]^arr[y-1]^arr[z-1];
}

void gen()
{
    srand(time(NULL));
    for(int i=0;i<n;i++) arr[i]=rand()%100;
}

void print()
{
    for(int i=0;i<n;i++) cout<<arr[i]<<' ';
    cout<<endl;
    for(int i=0;i<n;i++) cout<<a[0][i]<<' ';
    cout<<endl;
}

int process()
{
    int val,j=0,i;
    val=n-2;
    for(i=0;i<val;i++)
    {
       a[0][i]=getval(i,i+1,i+2);
    }
    a[0][i]=getval(1,i+1,i+2);i++;
    a[0][i]=getval(1,2,i+1);i++;
    a[0][i]=a[0][0];
    for(i=0;i<n;i++)
    {
        a[1][i]=a[0][i]^a[0][i+1];
    }
    a[1][i]=a[1][0];
    a[1][i+1]=a[1][1];
    n--;
    cout<<(a[0][n]^a[1][n+2])<<' ';
    for(i=0;i<n;i++) cout<<(a[0][i]^a[1][i+2])<<' ';
    cout<<endl;
    n++;
    return val;
}

int main()
{
    n=5;
    gen();
    process();
    print();
    return 0;
}