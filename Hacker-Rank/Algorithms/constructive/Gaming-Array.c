#include<stdio.h>

int secmax,secpos;

int maxpos(int n,int *a)
{
  int i,max=0,pos=0;
  secmax=secpos=-1;
  for(i=0;i<n;i++)
  {
    if(a[i]>max)
    {
      max=a[i];
      secpos=pos;
      pos=i;
    }
  }
  return pos;
}

void fun()
{
  int n,i,flag=0;
  scanf("%d",&n);
  int a[n];
  for(i=0;i<n;i++) scanf("%d",a+i);
  i=0;
  while(n>0)
  {
    n=maxpos(n,a);
    if(n!=0)
    {
      n=secpos;
    }
    else
    {
      i++;
      break;
    }
    i+=2;
  }
  if(i&1) printf("BOB\n");
  else printf("ANDY\n");
}

int main(int argc, char const *argv[]) {
  int n;
  scanf("%d",&n);
  while(n--) fun();
  return 0;
}
