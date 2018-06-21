#include<stdio.h>
#include<string.h>
void strriv(char s)
{
  int len=strlen(s),i=0,op;
  op=len/2-1;
  len--;
  while(i<=op)
  {
    s[i]=s[i]+s[len-i]-(s[len-i]=s[i]);
    i++;
  }
}

int main(int argc, char const argv[]) {
  int sum,i=0,j=0,k,tmp,carry=0;
  char m[10],n[10],r[10];
  scanf("%s\n%s",m,n);
  strriv(m);
  strriv(n);
  while(m[i]!=0&&n[i]!=0)
  {
    sum=(m[i]-'0')*(n[i]-'0');
    if(carry)
    {
      sum+=carry%10;
      carry/=10;
    }
    if(sum>9)
    {
      r[j]=sum%10+'0';
      carry+=sum/10;
    }
    else
    {
      r[j]=sum+'0';
    }
    i++;
    j++;
  }
  if(m[i]==0)
  {
    while(n[i]!=0)
    {
      if(carry)
      {
        sum=n[i]-'0'+carry%10;
        carry/=10;
        if(sum<10)
        {
          r[j]=sum+'0';
        }
        else
        {
            r[j]=sum%10+'0';
            carry+=sum/10;
        }
      }
      else r[j]=n[i];
      i++;
      j++;
    }
  }
  if(n[i]==0)
  {
    while(m[i]!=0)
    {
      if(carry)
      {
        sum=m[i]-'0'+carry%10;
        carry/=10;
        if(sum<10)
        {
          r[j]=sum+'0';
        }
        else
        {
            r[j]=sum%10+'0';
            carry+=sum/10;
        }
      }
      else r[j]=m[i];
      i++;
      j++;
    }
  }
  while(carry)
  {
    r[j++]=carry%10+'0';
    carry/=10;
  }
  r[j]=0;
  for(j=j-1;j>=0;j--) putchar(r[j]);
  return 0;
}
