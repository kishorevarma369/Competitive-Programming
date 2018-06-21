/*

      Question :-

          https://www.hackerrank.com/challenges/time-conversion

      ***************************************************************************
      --------------------written by KISHORE VARMA-------------------------------
      ***************************************************************************
*/
#include<string.h>
#include<stdio.h>
#define s timedata
int main()
{
  int temp;
  char timedata[10]; //07:05:45PM 12:50:55AM
  scanf("%s",timedata);
  if(timedata[8]=='P')
  {
      temp=(s[0]-'0')*10+(s[1]-'0');
      if(temp<12) temp+=12;
      temp=temp%24;
      s[1]=temp%10+'0';
      temp/=10;
      s[0]=temp+'0';
  }
  if(timedata[8]=='A')
  {
      temp=(s[0]-'0')*10+(s[1]-'0');
      temp=temp%12;
      s[1]=temp%10+'0';
      temp/=10;
      s[0]=temp+'0';
  }
  s[8]='\0';
  printf("%s\n",s);
}
