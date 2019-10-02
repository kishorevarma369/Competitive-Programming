#include<bits/stdc++.h>

using namespace std;

int n,a[108],res[108],q[5],pos;

void gen_query()
{
    for(int i=2;i<=6;i++) q[i%5]=a[(pos+i-2)%n];
    // q[2]=a[pos%n];
    // q[3]=a[(pos+1)%n];
    // q[4]=a[(pos+2)%n];
    // q[0]=a[(pos+3)%n];
    // q[1]=a[(pos+4)%n];
    cout<<"? ";
    for(int i=0;i<5;i++) cout<<q[i]<<' ';
    cout<<endl;
    cin>>res[q[2]]>>res[q[3]];
}

void perform()
{
    int req=n/2;
    if(n&1) req++;
    for(int i=0;i<req;i++) gen_query();
}

void pre()
{
    for(int i=0;i<108;i++) a[i]=i+1;
}


int main()
{
    int t;
    pre();
    cin>>t;
    while(t--)
    {
        cin>>n;
        pos=0;
        perform();
    }
}