#include<bits/stdc++.h>
using namespace std;

void fun()
{
  unsigned long long int no_sweets,no_prisoners,start;
  cin>>no_prisoners>>no_sweets>>start;
  int k=(no_sweets+start-1)%no_prisoners;
  if(k==0) cout<<no_prisoners<<'\n';
  else cout<<k<<'\n';
}

int main(int argc, char const *argv[])
{
  int n;
  cin>>n;
  while(n--) fun();
  return 0;
}
