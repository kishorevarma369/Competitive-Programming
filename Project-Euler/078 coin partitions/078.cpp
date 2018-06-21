#include<bits/stdc++.h>

using namespace std;

#define mycon 1000000
#define mymod 1000000

int main(int argc, char const *argv[])
{
  unsigned long long int *a,i,j;
  a=(unsigned long long int *)malloc(sizeof(unsigned long long int)*mycon);
  for(i=1;i<mycon;i++)
  {
    a[i]++;
    if(a[i]%mymod==0)
    {
      printf("%llu\n",a[i]);
      break;
    }
    for(j=i+1;j<mycon;j++)
    {
      a[j]+=a[j-i];
    }
  }
  printf("complete\n");
  return 0;
}
