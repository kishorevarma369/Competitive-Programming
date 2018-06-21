#include <bits/stdc++.h>

using namespace std;

long fun1(long size,vector<vector<long>>& table,long i,long j)
{
  if(i<0||j<0) return 0;
  return table[i][j];
}

void fun()
{
    long n,k,b;
    cin>>n>>k>>b;
    long size=n,i,j;
    vector<long> a(n);
    for(i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());
    vector<vector<long>> table(size,vector<long>(size,0));
    for(i=0;i<size;i++)
    {
      for(j=0;j<size;j++)
      {
        if(a[i]>=(k*a[j]+b))
        {
          table[i][j]=fun1(size,table,i-1,j-1)+1;
        }
        else table[i][j]=max(fun1(size,table,i-1,j),fun1(size,table,i,j-1));
      }
    }
    cout<<table[size-1][size-1]+1<<'\n';
}

int main() {
    int n;
    cin>>n;
    while(n--) fun();
    return 0;
}
