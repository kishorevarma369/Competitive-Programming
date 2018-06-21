/*
https://www.hackerrank.com/contests/mockcodestorm/challenges/sock-pair
*/
#include<stdio.h>

int main(int argc, char const *argv[]) {
  int n,c[101]={0},b,count=0,i;
  scanf("%d",&n);
  for(i=1;i<=n;i++)
  {
    scanf("%d",&b);
    c[b]++;
  }
  for(i=0;i<=100;i++) count+=c[i]/2;
  printf("%d\n",count);
  return 0;
}
