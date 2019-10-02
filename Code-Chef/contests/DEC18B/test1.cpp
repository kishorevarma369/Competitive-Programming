// 4 9 10 11
#include<bits/stdc++.h>

using namespace std;
int n=4;

void consecxor(int a[],int b[])
{
    cout<<"\nxored values:\n";
    a[n]=a[0];
    a[n+1]=a[1];
    for(int i=0;i<n;i++) cout<<(b[i]=(a[i]^a[i+1]^a[i+2]))<<' ';
}

int main(int argc, char const *argv[])
{
    srand(time(NULL));

    // cin>>n;
    int a[n+5],b[2][n+5];
    for(int i=0;i<n;i++) a[i]=rand()%50;
    cout<<"original values:\n";
    for(int i=0;i<n;i++) cout<<a[i]<<' ';
    consecxor(a,b[0]);
    return 0;
}
