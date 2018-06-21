#include<bits/stdc++.h>
using namespace std;

struct my
{
  int x,y,z;
};

typedef struct my myset;

int main(int argc, char const *argv[])
{
  int n,i,j,k;
  cin>>n;
  int a[n+1]={0};
  long count=0;
  vector<myset> v;
  for(i=0;i<n;i++)
  {
    if(!a[i])
    {
      for(j=i+1;j<n;j++)
      {
        if(!a[j])
        {
          k=n-i-j;
          if(k<0) break;
          if(!a[k]&&k!=i&&k!=j)
          {
            a[i]=a[j]=a[k]=1;
            myset m;
            m.x=i;m.y=j;m.z=k;
            v.push_back(m);
            count+=3;
            break;
          }
        }
      }
    }
  }
  cout<<count<<'\n';
  for(auto i:v)
  {
    cout<<i.x<<' '<<i.y<<' '<<i.z<<'\n';
    cout<<i.z<<' '<<i.x<<' '<<i.y<<'\n';
    cout<<i.y<<' '<<i.z<<' '<<i.x<<'\n';
  }
  return 0;
}
