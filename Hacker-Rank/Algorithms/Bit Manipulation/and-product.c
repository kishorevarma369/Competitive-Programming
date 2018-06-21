#include<stdio.h>

int main(int argc, char const *argv[]) {
  unsigned int n,i,j,k,count=0;
  scanf("%u",&n);
  while(n--)
  {
    scanf("%u %u",&i,&j);
    count=0;
    while(i!=j)
    {
      i>>=1;
      j>>=1;
      count++;
    }
    i<<=count;
    printf("%u\n",i);
  }
  return 0;
}
