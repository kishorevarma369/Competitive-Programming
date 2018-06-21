#include<stdio.h>

int main(int argc, char const *argv[])
{
  char s[100],*p,*q;
  int i=0,flag=1;
  scanf("%s",s);
  while(1)
  {
    flag=1;
    for(i=1;s[i]!=0;i++)
    {
      a:
      if(s[i]==s[i-1])
      {
        flag=0;
        p=s+i-1;
        q=s+i+1;
        while(*q!=0)
        {
          *p=*q;
          p++,q++;
        }
        *p=0;
        goto a;
      }
    }
    if(flag) break;
  }
  if(s[0]==0) printf("Empty String");
  else printf("%s\n",s);
  return 0;
}
