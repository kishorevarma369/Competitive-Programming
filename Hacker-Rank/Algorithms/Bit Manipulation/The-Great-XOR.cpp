#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
  int n,nbits=0;
  unsigned long long int a[33],k,pos=0,val;
  a[0]=1;
  for(k=1;k<33;k++) a[k]=a[k-1]<<1;
  cin>>n;
  while(n--)
  {
    cin>>val;
    pos=k=0;
    while(val!=0)
    {
      if(!(val&1))
      {
        k+=a[pos];
      }
      val>>=1;
      pos++;
    }
    cout<<k<<'\n';
  }
  return 0;
}
