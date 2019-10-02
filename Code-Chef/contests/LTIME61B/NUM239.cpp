#include<bits/stdc++.h>

using namespace std;

int get_lb(int a)
{
    return a-a%10;
}

int get_ub(int a)
{
    return a+(10-a%10==0?10:a%10);
}

int main(int argc, char const *argv[])
{
    int t,l,r,tl,tr,count=0,i,k;
    cin>>t;
    int a[100001]={0};
    for(i=2;i<100001;i++)
    {
        k=i%10;
        a[i]=a[i-1];
        if(k==2||k==3||k==9) a[i]++;
    }
    while(t--)
    {
        cin>>l>>r;
        cout<<a[r]-a[l-1]<<'\n';
    }
    return 0;
}
