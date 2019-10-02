#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
    ll n,i,k,c=0,val;
    cin>>n;
    char ch;
    ll a[n];
    for(i=0;i<n-1;i++)
    {
        cin>>k>>ch;
        val=0;
        while(k!=0)
        {
            val+=k%6;
            k/=6;
        }
        a[i]=val;
    }
    cin>>k;
    val=0;
    while(k!=0)
    {
        val+=k%6;
        k/=6;
    }
    a[i]=val;
    for(i=0;i<n;i++)
    {
        for(k=i+1;k<n;k++) if(a[i]>a[k]) c++;
    }
    cout<<c;
    return 0;
}