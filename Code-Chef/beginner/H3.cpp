#include<bits/stdc++.h>

using namespace std;
queue<int> Q;
int found[98765433],pres,a[3][3],power[10],vx,vy;
int ax[]={0,0,1,-1},by[]={1,-1,0,0};

void move(int x,int y)
{
    int t=pres+(a[x][y]-a[vx][vy])*power[vx*3+vy]+(a[vx][vy]-a[x][y])*power[x*3+y];
    cout<<t<<'\n';
}

int main()
{
    int t=1;
    for(int i=8;i>=0;i--) power[i]=t,t*=10;
    pres=123456789;
    t=pres;
    for(int i=2;i>=0;i--)
    {
        for(int j=2;j>=0;j--) a[i][j]=t%10,t/10;
    }
    vx=2,vy=2;
    move(0,0);
    //cout<<pres<<'\n';
    return 0;
}