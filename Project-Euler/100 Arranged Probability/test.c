#include<stdio.h>
#include<limits.h>
void main()
{
  unsigned long long int b = 15;
  unsigned long long int n = 21;
  unsigned long long int target = 1000000000000;
  unsigned long long int btemp,ntemp;
  while(n < target)
  {
      btemp = 3 * b + 2 * n - 2;
      ntemp = 4 * b + 3 * n - 3;
      b = btemp;
      n = ntemp;
  }
  printf("%llu\n",b);
}
