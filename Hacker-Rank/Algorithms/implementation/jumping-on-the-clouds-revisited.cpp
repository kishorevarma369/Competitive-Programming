#include <bits/stdc++.h>

using namespace std;

int jumpingOnClouds(vector <int> c, int k)
{
    int i=0,n=c.size(),health=100;
    for(;health>0;)
    {
        i+=k;
        health--;
        if(i>=n)
        {
          i-=n;
          if(c[i]) health-=2;
          if(i==0) break;
          continue;
        }
        if(c[i]) health-=2;
    }
    return health;
}

int main() {
    int n;
    int k;
    cin >> n >> k;
    vector<int> c(n);
    for(int c_i = 0; c_i < n; c_i++){
       cin >> c[c_i];
    }
    int result = jumpingOnClouds(c, k);
    cout << result << endl;
    return 0;
}
