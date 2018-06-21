#include<bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
  int n,rel,i,j,k=0,p,q,l,total=0;
  cin>>n>>rel;
  vector<int> v(n,-1);
  while(rel--)
  {
    cin>>i>>j;
    if(v[i]==-1)
    {
      if(v[j]==-1) v[i]=v[j]=k++;
      else v[i]=v[j];
    }
    else
    {
      if(v[j]==-1) v[j]=v[i];
      else
      {
        p=v[i];
        q=v[j];
        for(l=0;l<n;l++) if(v[l]==p||v[l]==q) v[l]=k;
        k++;
      }
    }
  }
  vector<int> index(k+1,0);
  for(i=0;i<n;i++)
  {
    if(v[i]==-1) index[k]++;
    else index[v[i]]++;
  }
  int size=index.size();
  for(i=0;i<size;i++)
  {
    for(j=i+1;j<size;j++) total+=index[i]*index[j];
  }
  l=(index[k]*(index[k]-1))/2;
  if(l>0) total+=l;
  cout<<total;
  return 0;
}
