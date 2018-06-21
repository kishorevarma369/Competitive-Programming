#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
  int n,i,j,k,t;
  cin>>n;
  int a[n];
  cin>>a[0];
  for(i=j=1;i<n;i++)
  {
    cin>>k;
    if(k!=a[j-1]) a[j++]=k;
  }
  n=j;
  cin>>t;
  j--;
  while(t--)
  {
    cin>>k;
    i=j;
    while(j>=0&&a[j]<k) j--;
    if(a[j]==k) cout<<j+1<<'\n';
    else cout<<j+2<<'\n';
    if(j<0)
    {
      while(t--)
      {
        cout<<"1\n";
      }
      return 0;
    }
  }
  return 0;
}
