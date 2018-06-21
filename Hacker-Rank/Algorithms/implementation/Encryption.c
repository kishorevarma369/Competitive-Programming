#include<stdio.h>
#include<string.h>
#include<math.h>

int main(int argc, char const *argv[])
{
  char s[100];
  scanf("%s",s);
  int len=strlen(s),i,j,rows,columns;
  i=ceil(sqrt(len));
  j=i-1;
  if(i*j>len) j=j+1;
  rows=j;
  columns=i;
  for(i=0;i<columns;i++)
  {
    for(j=i;j<len;j+=columns)
    {
      putchar(s[j]);
    }
    putchar(' ');
  }
  return 0;
}
