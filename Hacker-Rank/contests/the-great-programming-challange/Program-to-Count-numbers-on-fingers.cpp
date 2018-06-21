#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin>>n;
    if(n%8==1) cout<<"1";
    else if(n%8==5) cout<<"5";
    else if(n%4==0)
    {
        n/=4;
        if((n&1)==0) cout<<"2";
        else cout<<"4";
    }
    else if(n%4==2)
    {
        n-=2;
        n/=4;
        if((n&1)==0) cout<<"2";
        else cout<<"4";
    }
    else cout<<"3";
    return 0;
}
