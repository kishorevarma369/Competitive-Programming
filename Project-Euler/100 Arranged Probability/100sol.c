#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define test1
unsigned long long int isperfect2(unsigned long long int Some_integer)
{
  unsigned long long int temp;
  double test;
  test=sqrt((double)Some_integer);
  temp=test;
  if(temp==test) return temp;
  return 0;
}

//1168070918
//756872327473

void main()
{
  #ifdef test1
  unsigned long long int a=1,b,c;
  #else
  unsigned long long int a=1000000000001,b,c;
  #endif
  while(1)
  {
    b=1+2*a*(a-1);
    if(c=isperfect2(b))
    {
      printf("%llu %llu\n",(1+c)/2,a);
      #ifdef test1
        system("pause");
      #else
        break;
      #endif
    }
    a++;
  }
}
