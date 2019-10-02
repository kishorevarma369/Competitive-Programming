// 4 9 10 11
#include<bits/stdc++.h>

using namespace std;


int main(int argc, char const *argv[])
{
    srand(time(NULL));
    int n=5;
    cin>>n;
    int a[n+5];
    for(int i=0;i<n;i++) cin>>a[i];
    a[n]=a[0];
    a[n+1]=a[1];
    cout<<"original values:\n";
    for(int i=0;i<n;i++) cout<<a[i]<<' ';
    cout<<"\nxored values:\n";
    for(int i=0;i<n;i++) cout<<(a[i]^a[i+1]^a[i+2])<<' ';
    return 0;
}
