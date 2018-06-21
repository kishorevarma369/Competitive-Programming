#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
  int n,a=2,sum=2;
  scanf("%d",&n);
  while(n--)
  {
    a=(a*3)/2;
    sum+=a;
  }
  cout<<sum-a;
  return 0;
}
