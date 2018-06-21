#include<stdio.h>
#include<math.h>

int count=0,power=0,some=0,n=0,level;

void func(int val,int pres)
{
  static int i=0;
  i++;
  if(pres==n)
  {
    count++;
  }
  else if(pres<n)
  {
    if(i<=level)
    {
      func(val+1,pres);
      some=1;
      for(int i=0;i<power;i++) some*=val;
      func(val+1,pres+some);
    }
  }
  i--;
}

int main(int argc, char const *argv[])
{
  scanf("%d\n%d",&n,&power);
level=(int)pow(n,1.0/power);
  func(1,0);
  printf("%d\n",count);
  return 0;
}
