#include <bits/stdc++.h>

using namespace std;

int n,k,qx,qy;
// t means teta
pair<int,int> t0,t45,t90,t135,t180,t225,t270,t315;


void generate()
{
    t0=make_pair(qx,n);
    t90=make_pair(1,qy);
    t180=make_pair(qx,1);
    t270=make_pair(n,qy);
    //need to figure out
    if(qx<qy)
    {
t135=make_pair(1,qy-qx+1);
    }
    else{
        t45=make_pair(qx+qy-n,n);
        t135=make_pair(qx-qy+1,1);
        t225=make_pair(qx+qy-1,1);
        t315=make_pair(qx+qy-n,n);
    }
}

void print()
{
    cout<<t0.first<<','<<t0.second<<'\n'<<t45.first<<','<<t45.second<<'\n'<<t90.first<<','<<t90.second<<'\n'<<t135.first<<','<<t135.second<<'\n'<<t180.first<<','<<t180.second<<'\n'<<t225.first<<','<<t225.second<<'\n'<<t270.first<<','<<t270.second<<'\n'<<t315.first<<','<<t315.second;
}

int main()
{
    cin>>n>>k>>qx>>qy;
    generate();
    print();
    return 0;
}
