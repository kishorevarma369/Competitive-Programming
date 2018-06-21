#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
  int n,k,i,c=0,p,arr;
  cin>>n>>k;
  int b[k];
  for(i=0;i<k;i++) b[i]=0;
  for(i=0;i<n;i++)
  {
    cin>>arr;
    b[arr%k]+=1;
  }
  c=min(b[0],1);
  p=k/2;
  if(k%2) p++;
  for(i=1;i<p;i++)
  {
    c+=max(b[i],b[k-i]);
  }
  if(k%2==0) c+=min(b[p],1);
  cout<<c;
  return 0;
}
