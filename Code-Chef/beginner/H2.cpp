#include<bits/stdc++.h>

using namespace std;
queue<int> Q;
int found[98765433],pres,a[10],power[10],px;
int ax[]={0,0,1,-1},by[]={1,-1,0,0};

void move(int x,int y)
{
    int t=pres+(a[y]-a[x])*power[x]+(a[x]-a[y])*power[y];
    if(!found[t/10])
    {
        Q.push(t);
        found[t/10]=found[pres/10]+1;
    }
}

bool isvalid(int x,int y)
{
    if(x>=0&&y>=0&&x<3&&y<3) return true;
    return false;
}

void pre()
{
    int t=1,vx,vy,tx,ty;
    for(int i=8;i>=0;i--) power[i]=t,t*=10;
    found[12345678]=1;
    Q.push(123456789);
    while(!Q.empty())
    {
        t=pres=Q.front();
        Q.pop();
        for(int i=8;i>=0;i--)
        {
            if((t%10)==9) px=i;
            a[i]=t%10,t/=10;
        } 
        vy=px%3;
        vx=px/3;
        for(int i=0;i<4;i++)
        {
            tx=vx+ax[i],ty=vy+by[i];
            if(isvalid(tx,ty)) move(px,tx*3+ty);
        }
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