#include<bits/stdc++.h>

using namespace std;

tuple<int,int,int> extgcd(int a,int b)
{
    if(b==0) return {1,0,a};
    int x,y,g;
    tie(x,y,g)=extgcd(b,a%b);
    return {y,x-(a/b)*y,g};
}

int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    auto t=extgcd(a,b);
    int x,y,z;
    tie(x,y,z)=t;
    // cout<<z;
    // if(z<0) x*=-1,y*=-1,c*=-1,z*=-1;
    a/=z,b/=z,c/=z;
    x*=c,y*=c;
    // printf("%d %d %d %d",x,y,z,c);
    printf("x=%d+%d\ny=%d-%d",x,b,y,a);
    return 0;
}