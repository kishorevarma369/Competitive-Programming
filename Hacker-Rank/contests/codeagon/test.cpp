#include <bits/stdc++.h>

using namespace std;

// Complete the solve function below.

float slope(int x1,int y1,int x2,int y2)
{
    if(x2-x1)
    return abs(float(y2-y1)/(x2-x1));
}


int main()
{
    float f;
    map<float,int> m;
    f=abs(slope(2,3,3,4));
    m[f]++;
    f=abs(slope(1,2,1,3));
    cout<<f<<isnan(f)<<'\n';
    m[f]++;
    f=abs(slope(2,2,2,3));
    m[f]++;
    
    for(auto &i:m) cout<<i.first<<' '<<i.second<<'\n';
}