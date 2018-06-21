#include <bits/stdc++.h>

using namespace std;
#define mycon 1e6+1

void generate(vector<int> &prime)
{
  prime[0]=2;
  int i,j,primesize=1,flag;
  for(i=3;i<mycon;i+=2)
  {
    flag=1;
    for(j=0;j<primesize&&prime[j]*prime[j]<=i;j++)
    {
      if(i%prime[j]==0)
      {
        flag=0;
        break;
      }
    }
    if(flag)
    {
      prime[primesize++]=i;
    }
  }
  if(primesize==78498) prime.pop_back();
}

int maxDifference(int startVal, int endVal,vector<int> &prime)
{
  int i,lval=0,uval=0;
  auto ubound=upper_bound(prime.begin(),prime.end(),startVal);
  auto lbound=lower_bound(prime.begin(),prime.end(),endVal);
  if(ubound==prime.end()||lbound==prime.end())
  {
    cout<<"not";
    return 0;
  }
  int a,b,c,d;
  if(ubound>prime.begin())
  {
    a=*(ubound-1);
  }
  else a=0;
  if(lbound>prime.begin())
  {
    c=*(lbound-1);
  }
  else c=0;
  b=*(ubound);
  d=*(lbound);
  if(a>=startVal) b=a;
  if(d<=endVal) c=d;
  //cout<<"c="<<c<<"b="<<b<<'\n';
  if(c-b<=0) return 0;
  return c-b;
}

int main() {
    int q;
    cin >> q;
    vector<int> prime(78499);
    generate(prime);
    for(int a0 = 0; a0 < q; a0++)
    {
        int startVal;
        int endVal;
        cin >> startVal >> endVal;
        int result = maxDifference(startVal, endVal,prime);
        cout << result << endl;
    }
    return 0;
}
