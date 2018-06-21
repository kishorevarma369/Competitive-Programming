#include<bits/stdc++.h>

using namespace std;

void fun()
{
  int n,t,x,p=0,tmp;
  cin>>n>>t;
  int a[256]={0};
  tmp=t;
  while(t!=0)
  {
    p<<=1;
    p+=1;
    t>>=1;
  }
  t=tmp;
  p=p^t;
  for(i=0;i<n;i++)
  {
    cin>>x;
    if(t&x) continue;
    a[x]++;
  }
  
}

int main(int argc, char const *argv[])
{
  int n;
  cin>>n;
  while(n--) fun();
  return 0;
}
