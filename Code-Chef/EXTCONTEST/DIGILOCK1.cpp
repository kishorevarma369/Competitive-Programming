#include<bits/stdc++.h>

using namespace std;

#define uplim 100001

int n,q,a[3][uplim];

void pre()
{
    int val;
    for(int i=0;i<3;i++){
        for(int j=0;j<n;j++) cin>>val,a[i][val]=j;
    } 
}

int main()
{
    cin>>n>>q;
    pre();
    int val1,val2,val3,x,y,z,shifts;
    cin>>x>>y>>z;
    x=a[0][x];
    y=a[1][y];
    z=a[2][z];
    while(q--)
    {
        cin>>val1>>val2>>val3;
        val1=a[0][val1];
        val2=a[1][val2];
        val3=a[2][val3];
        shifts=(val1-x+n)%n;
        val2=(val2-shifts+n)%n;
        shifts=(val2-y+n)%n;
        val3=(val3-shifts+n)%n;
        if(val3==z) cout<<"YES\n";
        else cout<<"NO\n";
        // 1 2 0
        // 0 1 2
        
    }
    return 0;
}