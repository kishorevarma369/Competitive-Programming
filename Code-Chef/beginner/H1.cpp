#include<bits/stdc++.h>

using namespace std;
queue<int> Q;
int found[98765433],pres,a[10],power[10];
bool prime[20];

void move(int x,int y)
{
    int t=pres+(a[y]-a[x])*power[x]+(a[x]-a[y])*power[y];
    if(!found[t/10])
    {
        Q.push(t);
        found[t/10]=found[pres/10]+1;
    }
}

void pre()
{
    int t;
    prime[2]=true;
    for(int i=3;i<20;i+=2) prime[i]=true;
    for(int i=3;i<20;i+=2)
    {
        if(prime[i]) for(int j=i+i;j<20;j+=i) prime[j]=false;
    }
    t=1;
    for(int i=8;i>=0;i--) power[i]=t,t*=10;
    found[12345678]=1;
    Q.push(123456789);
    while(!Q.empty())
    {
        t=pres=Q.front();
        Q.pop();
        for(int i=8;i>=0;i--) a[i]=t%10,t/=10;
        if(prime[a[0]+a[1]]) move(0,1);
        if(prime[a[0]+a[3]]) move(0,3);
        if(prime[a[1]+a[2]]) move(1,2);
        if(prime[a[1]+a[4]]) move(1,4);
        if(prime[a[2]+a[5]]) move(2,5);
        if(prime[a[3]+a[4]]) move(3,4);
        if(prime[a[3]+a[6]]) move(3,6);
        if(prime[a[4]+a[5]]) move(4,5);
        if(prime[a[4]+a[7]]) move(4,7);
        if(prime[a[5]+a[8]]) move(5,8);
        if(prime[a[6]+a[7]]) move(6,7);
        if(prime[a[7]+a[8]]) move(7,8);
    }
}

int main()
{
    pre();
    int n,val,v;
    cin>>n;
    while(n--)
    {
        val=0;
        for(int i=0;i<8;i++) cin>>v,val=val*10+v;
        cin>>v;
        cout<<found[val]-1<<'\n';
    }
    return 0;
}