#include <bits/stdc++.h>

using namespace std;
int main() {
    int l,r,max=0,i,j;
    cin>>l>>r;
    for(i=l;i<=r;i++)
    {
      for(j=i+1;j<=r;j++) if((i^j)>max) max=i^j;
    }
    cout<<max<<'\n';
    return 0;
}
