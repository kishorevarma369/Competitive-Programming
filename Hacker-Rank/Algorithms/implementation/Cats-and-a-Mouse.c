#include<stdio.h>
#include<stdlib.h>
#define a Cat_a
#define b Cat_b
#define c Mouse_c
void fun()
{
  int a,b,c;
  scanf("%d %d %d",&a,&b,&c);
  if(abs(a-c)>abs(b-c)) printf("Cat B\n");
  else if(abs(a-c)<abs(b-c)) printf("Cat A\n");
  else printf("Mouse C\n");
}

int main(int argc, char const *argv[])
{
  int n,i;
  scanf("%d",&n);
  for(i=0;i<n;i++) fun();
  return 0;
}
