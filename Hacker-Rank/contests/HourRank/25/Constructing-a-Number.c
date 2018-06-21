#include<stdio.h>

void fun()
{
  int n,i=0,sum=0,t;
  char ch;
  scanf("%d",&n);
  for(i = 0; i < n; i++)
  {
    scanf("%d",&t);
    while(t!=0)
    {
      sum+=t%10;
      t/=10;
    }
  }
  if(sum%3==0) printf("%s\n","Yes");
  else printf("%s\n","No");
}

int main(int argc, char const *argv[])
{
  int n,i;
  scanf("%d",&n);
  for(i=0;i<n;i++) fun();
  return 0;
}
