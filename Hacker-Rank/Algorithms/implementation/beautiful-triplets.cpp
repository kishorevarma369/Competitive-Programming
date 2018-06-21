#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
  int n,k,i,j,up,l,count=0;
  cin>>n>>k;
  int a[n];
  for(i=0;i<n;i++) cin>>a[i];
  up=n-2;
  for(i=0;i<up;i++)
  {
    l=a[i]+k;
    for(j=i+1;j<=up&&a[j]<l;j++) ;
    if(j>up) continue;
    if(a[j]==l)
    {
      l=a[j]+k;
      for(j=j+1;j<n&&a[j]<l;j++) ;
      if(j!=n&&a[j]==l) count++;
    }
  }
  cout<<count<<'\n';
  return 0;
}
