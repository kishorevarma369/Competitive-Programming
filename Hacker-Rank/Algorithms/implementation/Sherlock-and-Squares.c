#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void fun()
{
  int a,b,c,k,count=0;
  scanf("%d %d",&a,&b);
  c=sqrt(a);
  if(c*c!=a) c+=1;
  while((k=c*c)<=b)
  {
      count++;
      c++;
  }
  printf("%d\n",count);
}

int main(int argc, char const *argv[])
{
  int n;
  scanf("%d",&n);
  while(n--) fun();
  return 0;
}
