#include<bits/stdc++.h>

using namespace std;

void fun()
{
  int n,p,t,tot=0,i;
  cin>>n>>p;
  for(i=0;i<n;i++)
  {
    cin>>t;
    tot+=t;
  }
  if(tot%p==0) cout<<"Yes\n";
  else cout<<"No\n";
}

int main(int argc, char const *argv[])
{
  int n;
  cin>>n;
  while(n--) fun();
  return 0;
}
