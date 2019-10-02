#include<bits/stdc++.h>
using namespace std;



#define mymod 1000000007
template<typename t>
t mod(t a,t b)
{
    return (t)((a%mymod)*(b%mymod))%mymod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    long long int at,dt;
    __int128 n,sum,a,l;
    while(t--)
    {
        cin>>dt>>at;
        at--,dt--;
        a=at;
        l=a%dt;
        n=((a-l)/dt)+1;
        if(n&1)
        {   
            sum=(a+l)/2;
            sum=mod(sum,n);
        }   
        else{
            sum=n/2;
            sum=mod(sum,(a+l));
        } 
        dt=sum;
        cout<<dt<<'\n';
    }
    return 0;
}
