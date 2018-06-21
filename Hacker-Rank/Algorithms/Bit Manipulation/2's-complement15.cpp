#include<bits/stdc++.h>
using namespace std;

unsigned long long int cou;
int fun(int p,int q)
{
  cou=0;
  while(p<=q)
  {
    cou+=__builtin_popcount(p);
      p++;
  }
  return cou;
}

int main(int argc, char const *argv[])
{
  int i,j,n;
  cin>>n;
  while(n--)
  {
    cin>>i>>j;
    cout<<fun(i,j)<<endl;
  }
  return 0;
}
