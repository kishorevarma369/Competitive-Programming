#include<bits/stdc++.h>

using namespace std;

void fun()
{
  int m,c,k,val,choc=0;
  cin>>m>>c>>k;
  val=m/c;
  choc+=val+val/k;
  val=val%k+val/k;
  while(val>=k)
  {
    choc+=val/k;
    val=val%k+val/k;
  }
  cout<<choc<<'\n';
}

int main(int argc, char const *argv[]) {
  int n;
  cin>>n;
  while(n--) fun();
  return 0;
}
