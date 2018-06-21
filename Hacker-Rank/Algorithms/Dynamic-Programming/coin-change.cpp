#include <bits/stdc++.h>

using namespace std;

long valat(vector<long> &v,long val)
{
  if(val<0) return 0;
  if(val==0) return 1;
  return v[val];
}

long getWays(long n, vector < long > c)
{
  int i,j;
  vector<long> v(n+1,0);
  v[0]=1;
  for(i=0;i<c.size();i++)
  {
    for(j=c[i];j<=n;j++)
    {
      v[j]+=valat(v,j-c[i]);
    }
  }
  return v[n];
}

int main() {
    int n;
    int m;
    cin >> n >> m;
    vector<long> c(m);
    for(int c_i = 0; c_i < m; c_i++){
       cin >> c[c_i];
    }
    long ways = getWays(n, c);
    cout<<ways<<'\n';
    return 0;
}
