#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
  int n,i,rot,k,l,m;
  cin>>n>>rot>>k;
  int a[n];
  for(i=0;i<n;i++) cin>>a[i];
  rot=rot%n;
  while(k--)
  {
    cin>>l;
    m=n-rot;
    cout<<a[(m+l)%n]<<'\n';
  }
  return 0;
}
