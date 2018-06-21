/*
COIN FLIP
*/
#include<bits/stdc++.h>

using namespace std;

void fun()
{
  int n;
  cin>>n;
  int a,b,c,k;
  while(n--)
  {
    cin>>a>>b>>c;
    if(b&1) k=(b+1)/2;
    else k=b/2;
    if(a==c) cout<<b-k<<'\n';
    else cout<<k<<'\n';
  }
}

int main(int argc, char const *argv[])
{
  int n;
  cin>>n;
  while(n--)
  {
    fun();
  }
  return 0;
}
