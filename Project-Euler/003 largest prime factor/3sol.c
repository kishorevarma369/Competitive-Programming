/*

       --------------------written by KISHORE VARMA-------------------------------

       **************************************************************************
       Largest prime factor                                            Problem 3

       The prime factors of 13195 are 5, 7, 13 and 29.

       What is the largest prime factor of the number 600851475143 ?

                   answer is                 6857
                                ------------------------------------

       *************************************************************************
    ideas :-

        1)  start with i=2 and proceed when i<number
            ->  divide number as long as number%i==0
            -> assign it to largest_prime_factor or lpf

        thats it we are ready to solve this Problem :)

      ***************************************************************************
      --------------------written by KISHORE VARMA-------------------------------
      ***************************************************************************
*/
#include<stdio.h>
#define maxlimit 1000000
typedef unsigned long long int uul;
#define largest_prime_factor lpf
//given number is 600,851,475,143
int main()
{
    uul number=600851475143,largest_prime_factor=0,i;
    for(i=2;i<=number;i++)
    {
      if(number%i==0)
      {
        while(number%i==0) number/=i;
        largest_prime_factor=i;
      }
    }
    printf("%llu\n",largest_prime_factor);
    return 0;
}
