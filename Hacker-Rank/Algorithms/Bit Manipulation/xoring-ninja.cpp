#include<bits/stdc++.h>

using namespace std;
const int ba=1e9+7;
void fun()
{
  int n,i,t,tot=0;
  cin>>n;
  for(i=0;i<n;i++)
  {
    cin>>t;
    tot|=t;
  }
  for(i=1;i<n;i++) tot=(tot*2)%ba;
  cout<<tot<<'\n';
}

int main(int argc, char const *argv[])
{
  int n;
  cin>>n;
  while(n--) fun();
  return 0;
}
