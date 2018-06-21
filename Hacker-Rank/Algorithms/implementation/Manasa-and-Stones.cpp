#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,t,a,b,k,i,prev;
    cin >> t;
    while(t--)
    {
      cin>>n>>a>>b;
      if(a>b) swap(a,b);
      k=n*a-b;
      if(a==b)
      {
        k=k-a+b;
        cout<<k<<'\n';
        continue;
      }
      for(i=0;i<n;i++)
      {
        k=k-a+b;
        cout<<k<<' ';
      }
      cout<<'\n';
    }
    return 0;
}
