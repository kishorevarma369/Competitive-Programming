#include<bits/stdc++.h>

using namespace std;

#define uplim 50005

int n,a[uplim],b[uplim];

void get_data()
{
    int tn=n-2,i;
    for(i=0;i<tn;i++)
    {
        // cout<<"1 "<<i+1<<' '<<i+2<<' '<<i+3<<endl;
        cin>>a[i];
    } 
    // cout<<"1 1 "<<n-1<<' '<<n<<endl;
    cin>>a[i++];
    // cout<<"1 1 2 "<<n<<endl;
    cin>>a[i++];
}

void process()
{
    get_data();
    a[n]=a[0];
    int i;
    for(i=0;i<n;i++)
    {
        b[i]=a[i]^a[i+1];
    }
    b[n]=b[0];
    b[n+1]=b[1];
    cout<<(a[n-1]^b[1])<<' ';
    n--;
    for(i=0;i<n;i++) cout<<(a[i]^b[i+2])<<' ';
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        process();
    }
    return 0;
}