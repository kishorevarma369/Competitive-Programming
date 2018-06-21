#include<stdio.h>
int main()
{
  int week=2,count=0;
  int month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
  for (int i = 1901; i < 2000; i++)
  {
    for (int j = 0; j < 12; j++) {
      week+=month[j];
      if((i%100&&i%400)||i%4==0) week++;
      week%=7;
      if(week==0) count++;
    }
  }
  printf("%d\n",count);
}
