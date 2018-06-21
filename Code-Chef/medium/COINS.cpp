#include<bits/stdc++.h>

using namespace std;

map<int,long long> dp;

long long optcoins(int n)
{
    if(n<12)
        return n;
    if(dp.count(n))
        return dp[n];
    dp[n]=optcoins(n/2)+optcoins(n/3)+optcoins(n/4);
    return dp[n];
}

int main()
{
    int x;
    while(scanf("%d",&x)!=EOF)
        printf("%lld\n",optcoins(x));
    return 0;
}
/*

mysolution time limit exceeded

:(

almost similar but why

#include<bits/stdc++.h>

using namespace std;
map<int,long long int> v;
void gen(long long int n,long long int g)
{
  g++;
  for(;g<=n;g++)
  {
      v[g]=v[g/2]+v[g/3]+v[g/4];
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


*/
