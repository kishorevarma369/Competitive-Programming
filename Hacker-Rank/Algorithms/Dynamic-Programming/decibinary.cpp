#include <bits/stdc++.h>

using namespace std;

long valat(vector<long> &v,long val)
{
  if(val<0) return 0;
  if(val==0) return 1;
  return v[val];
}
//493634659
//8001
long getWays(long n)
{
  int i,j,count=0,k=n;
  vector<long> v(n+1,0);
  while(k!=0)
  {
    k>>=1;
    count++;
  }
  k=1<<count;
  for(i=1;i<=k;i=i<<1)
  {
    for(j=i;j<=n&&j<;j++)
    {
      v[j]+=valat(v,j-i);
    }
  }
  return v[n];
}

int main() {
    int n;
    cin >> n;
    long ways = getWays(n);
    cout<<ways<<'\n';
    return 0;
}
