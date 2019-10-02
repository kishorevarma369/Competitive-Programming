#include<bits/stdc++.h>

using namespace std;

#define uplim 50005

int a[2][uplim],n;

int process()
{
    int tmp[3],val,j=0,i;
    val=n-2;
    for(i=0;i<val;i++)
    {
        cout<<"1 "<<i+1<<' '<<i+2<<' '<<i+3<<endl;
        cin>>a[0][i];
    }
    cout<<"1 1 "<<i+1<<' '<<i+2<<endl;
    cin>>a[0][i];i++;
    cout<<"1 1 2 "<<i+1<<endl;
    cin>>a[0][i];i++;
    a[0][i]=a[0][0];
    // cout<<"debug\n";
    // for(int i=0;i<=n;i++)
    // {
    //     cout<<a[0][i]<<' ';
    // }
    // cout<<'\n';
    //n--;
    for(i=0;i<n;i++)
    {
        a[1][i]=a[0][i]^a[0][i+1];
    }
    a[1][i]=a[1][0];
    a[1][i+1]=a[1][1];
    // for(int i=0;i<=n+1;i++)
    // {
    //     cout<<a[1][i]<<' ';
    // }
    // cout<<'\n';
    n--;
    cout<<2<<' '<<(a[0][n]^a[1][n+2])<<' ';
    for(i=0;i<n;i++) cout<<(a[0][i]^a[1][i+2])<<' ';
    cout<<endl;
    cin>>val;
    return val;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(process()==-1) break;
    }
    return 0;
}