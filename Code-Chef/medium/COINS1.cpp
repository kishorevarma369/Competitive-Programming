#include<bits/stdc++.h>

using namespace std;
map<int,long long int> v;
void gen(long long int n,long long int g)
{
  g++;
  for(;g<=n;g++)
  {
      v[g]=max(g,v[g/2]+v[g/3]+v[g/4]);
  }
}

int main(int argc, char const *argv[])
{
  int i=0;
  long long int g=12,n;
  for(g=0;g<12;g++) v[g]=g;
  g--;
  while(scanf("%lld",&n)!=EOF)
  {
    if(n>g)
    {
      gen(n,g);
      g=n;
    }
    cout<<v[n]<<'\n';
  }
  return 0;
}
