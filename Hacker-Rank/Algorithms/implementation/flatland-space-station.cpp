#include <bits/stdc++.h>
//easy but made me think for some time
using namespace std;

int flatlandSpaceStations(int n, vector <int> c)
{
    int i=0,ma,beg;
    for(i=0;i<n;i++) if(c[i]) break;
    ma=i;
    beg=i;
    i++;
    while(i<n)
    {
      for(;i<n;i++) if(c[i]) break;
      if(i!=n)
      {
        if(ma<((i-beg)/2)) ma=(i-beg)/2;
      }
      else if(ma<i-beg-1) ma=i-beg-1;
      beg=i;
      i++;
    }
    return ma;
}

int main() {
    int n;
    int m,j;
    cin >> n >> m;
    vector<int> c(n,0);
    for(int c_i = 0; c_i < m; c_i++){
       cin >> j;
       c[j]=1;
    }
    int result;
    if(m==n) result=0;
    else result = flatlandSpaceStations(n, c);
    cout << result << endl;
    return 0;
}
