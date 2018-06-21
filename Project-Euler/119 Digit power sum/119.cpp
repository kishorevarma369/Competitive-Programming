#include<iostream>
#include<set>

using namespace std;

typedef unsigned long long int uul;
const uul maxlim=1e16;

int sumofdigits(uul input)
{
  int sum=0;
  while(input!=0)
  {
    sum+=input%10;
    input/=10;
  }
  return sum;
}

int main(int argc, char const *argv[])
{
  uul c;
  int i;
  set<uul> res;
  for (i=2;i<=100; i++)
  {
    c=1;
    while(c<maxlim/i)
    {
      c*=i;
      if(sumofdigits(c)==i&&c>9) res.insert(c);
    }
  }
  int j=0;
  for (auto x:res) {
    cout<<++j<<' '<<x<<'\n';
  }
  return 0;
}
