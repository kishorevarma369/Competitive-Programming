#include<stdio.h>
#include<stdlib.h>

void fun()
{
  char s[100];
  scanf("%s",s);
  int b=atoi(s),i=0,c=0;
  while(s[i]!=0)
  {
    if(s[i]-'0')
    {
      if(b%(s[i]-'0')==0) c++;
    }
    i++;
  }
  printf("%d\n",c);
}

int main(int argc, char const *argv[])
{
  int n;
  scanf("%d",&n);
  while(n--) fun();
  return 0;
}
