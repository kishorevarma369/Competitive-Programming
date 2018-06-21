/*

       --------------------written by KISHORE VARMA-------------------------------

       **************************************************************************
       Summation of primes                                             Problem 10

       The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

       Find the sum of all the primes below two million.

                   answer is                  142913828922
                                ------------------------------------

       *************************************************************************
    ideas :-

        1) generating primes everytime is a pain so create a some functions to handle
           this job.
        2) lets assume that all numbers are prime and assign value 1(TRUE) for all >=2
           since 2 is prime its multiples will not be prime
                i.e., 4,8,16,32,................ set primeno[primepos]=0;
            now 3 has 1 so do the same job as above.
            4 is not a prime skipped
            primeno[5] is 1 so do the same as done with 2

            ..........proceed................

        At the end we will have all primes marked as 1 and remaining as 0

                        (  or  )

        any number can be declared as prime if none of the primes less than
        sqrt(n) divides the number.

        ******    place everything except main in a header file so we can reduce
        ******    the work to generate primes everytime

        thats it we are ready to solve this Problem :)

      ***************************************************************************
      --------------------written by KISHORE VARMA-------------------------------
      ***************************************************************************
*/
#include<stdio.h>
#include<stdlib.h>//for dynamic memory allocation
#include<stdbool.h>// for using bool in c

//place everything from here till freeprime in a header file
#define MAX_PRIME 2000000

bool *primeno=NULL;
int primepos=2;

int isprime(int n)
{
  if(n<=1) return 0;
  for(int i=0;i*i<=n;i++)
  {
    while(i*i<=n&&primeno[i]==0) i++;
    if(n%i==0) return 0;
  }
  return 1;
}

void primegen()
{
  primeno=(bool*)malloc(sizeof(bool)*MAX_PRIME);
  primeno[2]=1;
  for(int i=3;i<MAX_PRIME;i++)
  {
    if(isprime(i))
    {
       primeno[i]=1;
       primepos=i;
    }
    else primeno[i]=0;
  }
}

void freeprime()
{
  free(primeno);
}

int main()
{
    primegen();
    int i=2;//primes start from 2
    unsigned long long int sum=0;
    while(i<MAX_PRIME)
    {
      if(primeno[i]) sum+=i;
      i++;
    }
    printf("%llu\n",sum);
    freeprime();
}
