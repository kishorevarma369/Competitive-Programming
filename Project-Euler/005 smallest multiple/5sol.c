/*

       --------------------written by KISHORE VARMA-------------------------------

       **************************************************************************
       Smallest multiple                                                Problem 5

       2520 is the smallest number that can be divided by each of the numbers from
       1 to 10 without any remainder.

       What is the smallest positive number that is evenly divisible by all of the
       numbers from 1 to 20?

                   answer is                 232792560
                                ------------------------------------

       *************************************************************************
    ideas :-

        1)  any number can be expressed as x=( 2 ^ a )*( 3 ^ b )*.....

            In order to do this
            ->the largest power of 2 i.e., 2^x less than 20 is 2^4
              any number of 2's power or multiple of 2, less than 20 can divide x
              if i take 4 for a

            //ly do it for 3,5,7 .. all primes less than 20 and greater than 0

        thats it we are ready to solve this Problem :)

      ***************************************************************************
      --------------------written by KISHORE VARMA-------------------------------
      ***************************************************************************
*/
#include<stdio.h>
#define ul 20 //upper limit

void main()
{
  int isprime,prime[7],primepos=0;
  prime[primepos++]=2;
  for(int i=3;i<ul;i++)
  {
    isprime=1;
    for(int j=0;prime[j]*prime[j]<=i;j++)
    {
      if(i%prime[j]==0)
      {
        isprime=0;
        break;
      }
    }
    if(isprime) prime[primepos++]=i;
  }
  //generated all primes less than 20 by above loop
  int answer=1,temp,flag=0;
  for(int i=0;i<primepos;i++)
  {
    temp=prime[i];
    while(temp<ul) temp*=prime[i];
    temp/=prime[i];
    answer*=temp;
  }
  printf("%d\n",answer);
}
