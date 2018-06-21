#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

void printarrrev(char *s)
{
  int k=strlen(s)-1;
  while(k>=0)
  {
    putchar(s[k]);
    k--;
  }
}

void multiplystring(char *s,int x)
{
  int i=0,j=0,carry=0;
  while(s[i]!='\0')
  {
    j=((s[i]-'0')*x)+carry;
    carry=0;
    if(j>9)
    {
      s[i]=j%10+'0';
      carry=j/10;
    }
    else s[i]=j%10+'0';
    i++;
  }
  while(carry!=0)
  {
    s[i++]=carry%10+'0';
    carry/=10;
  }
  s[i]='\0';
}

int main() {
    int n;
    scanf("%d", &n);
    char s[1000];
    s[0]='1';
    s[1]=0;
    while(n!=1)
    {
        multiplystring(s,n--);
    }
    printarrrev(s);
    return 0;
}
