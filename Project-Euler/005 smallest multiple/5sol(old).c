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
#include<math.h>
#define k 20
void main()
{
  int i,prime=1,j=0,l=0,lov,prod=1,a[15];
  a[j++]=2;
  lov=a[j-1];
  while(lov<k)
  {
    lov*=2;
    prod*=2;
  }
  for(i=3;i<k+1;i++)
  {
    prime=1;
    for(l=0;a[l]<=sqrt(i)&&l<j;l++)
    {
      if(i%a[l]==0)
      {
        prime=0;
        break;
      }
    }
    if(prime)
    {
      a[j++]=i;
      lov=a[j-1];
      while(lov<k)
      {
        lov*=a[j-1];
        prod*=a[j-1];
      }
    }
  }
  printf("%llu\n",prod);
}
