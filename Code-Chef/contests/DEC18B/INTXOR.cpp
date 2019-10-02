#include<bits/stdc++.h>

using namespace std;

#define uplim 50005

int a[2][uplim],n;

void process()
{
    int tmp[3],val,j=0,tn,i;
    // for(int i=0;i<n;i++,j++)
    // {
    //     tmp[0]=i+1;
    //     tmp[1]=(i+)%n;
    //     tmp[2]=(i+3)%n;
    //     sort(tmp,tmp+3);
    //     cout<<"1 "<<tmp[0]<<' '<<tmp[1]<<' '<<tmp[2]<<endl;
    //     cin>>a[0][j];
    // }
    val=n-2;
    for(i=0;i<val;i++,j++)
    {
        cout<<"1 "<<i+1<<' '<<i+2<<' '<<i+3<<endl;
        cin>>a[0][j];
    }
    cout<<"1 1 "<<i+1<<' '<<i+2<<endl;
    cin>>a[0][j];j++,i++;
    cout<<"1 1 2 "<<i+1<<endl;
    cin>>a[0][j];j++,i++;
    a[0][j]=a[0][0];
    tn=j;
    for(int i=0;i<tn;i++)
    {
        a[1][i]=a[0][i]^a[0][i+1];
    }
    a[1][j]=a[1][0];
    a[1][j+1]=a[1][1];
    cout<<2<<' '<<a[0][];
    for(int i=0;i<j;i++) cout<<(a[0][i]^a[1][i])<<' ';
    cout<<endl;
    cin>>val;
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