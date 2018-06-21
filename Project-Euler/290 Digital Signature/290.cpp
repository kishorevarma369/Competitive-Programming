#include<iostream>
typedef unsigned long long int uul;
using namespace std;

void multiplystring(char *s,uul x)
{
  uul i=0,j=0,carry=0;
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

int sumofdigits(char *s)
{
  int sum=0;
  while(*s!='\0')
  {
    sum+=*s-'0';
    s++;
  }
  return sum;
}

void addtostring(char *s,int x)
{
  int i=0,j=0,carry=x,k=0;
  j=strlen(s);
  while(i<j)
  {
    k=s[i]-'0'+carry;
    carry=0;
    if(k>9) carry=(k/10);
    s[i]=(k%10)+'0';
    i++;
  }
  while(carry!=0)
  {
      if(carry>9)
      {
        s[i++]=(carry%10)+'0';
        carry/=10;
      }
      else
      {
        s[i++]=carry+'0';
        break;
      }
  }
  s[i]='\0';
}


int main(int argc, char const *argv[])
{
  char no[50]="137",no1[50];
  for (uul i = 0; i < 10000; i++)
  {
    strcpy(no1,no);
    multiplystring(no1,i);
    if(sumofdigits(no1)==x) cout<<no1;
  }
  return 0;
}
