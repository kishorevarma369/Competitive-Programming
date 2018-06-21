#include<stdio.h>
#define val 21
int main(int argc, char const *argv[])
{
  long long int a[val][val],i,j;
  for (i = 1; i < val; i++) a[i][0]=a[0][i]=1;
  for (i = 1; i < val; i++) for (j = 1; j < val; j++) a[i][j]=a[i-1][j]+a[i][j-1];
  printf("%lld",a[val-1][val-1]);
  return 0;
}
