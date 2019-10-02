#include <bits/stdc++.h>

using namespace std;
#define te
int n,k,qx,qy;
// t means teta 
pair<int,int> t0,t45,t90,t135,t180,t225,t270,t315;


void generate()
{
    int c,x,y;
    t0=make_pair(n,qy);
    t90=make_pair(qx,n);
    t180=make_pair(1,qy);
    t270=make_pair(qx,1);
    //took lot of time to figure out
    c=qy-qx;
    x=(c<0?abs(c):0)+1;
    t225=make_pair(x,x+c);
    x=c>0?n-c:n;
    t45=make_pair(x,x+c);
    c=qx+qy;
    x=c>n?c-n:1;
    t135=make_pair(x,-x+c);
    x=c<=n?c-1:n;
    t315=make_pair(x,-x+c);
}

void handle()
{
    int x,y;
    int ax,ay;
    cin>>x>>y;
    if(x==qx)
    {
        //handle t0 t180
        if(y>qy)
        {
            tie(ax,ay)=t90;
            if(y<ay) t90=make_pair(ax,y-1);
        }
        if(y<qy)
        {
            tie(ax,ay)=t270;
            if(y>ay) t270=make_pair(ax,y+1);
        }
    }
    else if(y==qy)
    {
        if(x>qx)
        {
            tie(ax,ay)=t0;
            if(x<ax) t0=make_pair(x-1,ay);
        }
        if(x<qx)
        {
            tie(ax,ay)=t180;
            if(x>ax) t180=make_pair(x+1,ay);
        }
    }
    else
    {
        int m1=x-qx,m2=y-qy;
        if(abs(m1)==abs(m2))
        {
            if(m1<0&&m2<0)
            {
                tie(ax,ay)=t225;
                if(y>ay) t225=make_pair(x+1,y+1);
            }
            else if(m1<0&&m2>0)
            {
                tie(ax,ay)=t135;
                if(y<ay) t135=make_pair(x+1,y-1);
            }
            else if(m1>0&&m2<0)
            {
                tie(ax,ay)=t315;
                if(y>ay) t315=make_pair(x-1,y+1);
            }
            else if(m1>0&&m2>0)
            {
                tie(ax,ay)=t45;
                if(y<ay) t45=make_pair(x-1,y-1);
            }
        }
    }
}
#ifndef test
void answer()
{
    int val=0,x,y;
    tie(x,y)=t0;
    val+=abs(x-qx);
    tie(x,y)=t45;
    val+=abs(x-qx);
    tie(x,y)=t90;
    val+=abs(y-qy);
    tie(x,y)=t135;
    val+=abs(x-qx);
    tie(x,y)=t180;
    val+=abs(x-qx);
    tie(x,y)=t225;
    val+=abs(x-qx);
    tie(x,y)=t270;
    val+=abs(y-qy);
    tie(x,y)=t315;
    val+=abs(x-qx);
    cout<<val<<'\n';
}
#else
void answer()
{
    cout<<"test\n";
    int val=0,x,y;
    tie(x,y)=t0;
    cout<<x<<' '<<y<<'\n';
    tie(x,y)=t45;
    cout<<x<<' '<<y<<'\n';
    tie(x,y)=t90;
    cout<<x<<' '<<y<<'\n';
    tie(x,y)=t135;
    cout<<x<<' '<<y<<'\n';
    tie(x,y)=t180;
    cout<<x<<' '<<y<<'\n';
    tie(x,y)=t225;
    cout<<x<<' '<<y<<'\n';
    tie(x,y)=t270;
    cout<<x<<' '<<y<<'\n';
    tie(x,y)=t315;
    cout<<x<<' '<<y<<'\n';
    //cout<<val<<'\n';
}
#endif

int main()
{
    cin>>n>>k>>qx>>qy;
    generate();
    while(k--)
    {
        handle();
    }
    answer();
    return 0;
}
