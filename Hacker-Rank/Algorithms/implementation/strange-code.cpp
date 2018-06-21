#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
  long long int n,pres=3,prev,val;
  cin>>n;
  while(pres-2<=n)
  {
    prev=pres;
    pres*=2;
  }
  val=prev-2;
  cout<<prev-(n-val);
  return 0;
}
