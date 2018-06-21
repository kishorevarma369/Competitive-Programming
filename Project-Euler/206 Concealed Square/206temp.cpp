#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
  char s[100];
  long long int a=138902663,k,l,i=8;
  while(1)
  {
    k=(a*a)/100,i=8;
    while(k!=0)
    {
      if(k%10!=i--) break;
      k/=100;
    }
    if(k==0) break;
    i=8;
    a-=6;
    k=(a*a)/100;
    while(k!=0)
    {
      if((k%10)!=i) break;
      i--;
      k/=100;
    }
    if(k==0) break;
    a-=4;
  }
  cout<<"a="<<a<<"0\na*a="<<a*a;
  return 0;
}
