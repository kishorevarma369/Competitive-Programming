/*

       --------------------written by KISHORE VARMA-------------------------------

       **************************************************************************
       Large non-Mersenne prime                                         Problem 97

       The first known prime found to exceed one million digits was discovered in 1999,
       and is a Mersenne prime of the form (2^6972593)−1; it contains exactly 2,098,960
       digits.Subsequently other Mersenne primes, of the form 2p−1, have been found
       which contain more digits.However, in 2004 there was found a massive non-Mersenne
       prime which contains 2,357,207 digits: 28433×(2^7830457)+1.

       Find the last ten digits of this prime number.

                   answer is                8739992577
                                ------------------------------------

       *************************************************************************
    ideas :-

        1)  using bignum library to solve it
                  - but it takes significant amount of time to calculate 2^7830457 -
                  after all its needed to solve this problem however

        2)  using hermats and eulers(divisibility) theorem.which is extensively used in encryption.

                  phi(n) = no of relative primes to n less than n

                  i.e., gcd(i,n)=1 for i = 1,2...n-1

                 if m and n are relatively prime then

                             phi(n)
                        ( m )
                         -----  =  1
                          n

         3)   but here 2^junk and 10^some are not relatively prime
                      so , i change 10^some as (2^some)*(5^some)
                      so now we can write as k = (2 ^ (junk-some) ) % (5^some)
              find the remainder(k) and multiply with 2^10 we get last 10 digits.

        thats it we are ready to solve this Problem :)

      ***************************************************************************
      --------------------written by KISHORE VARMA-------------------------------
      ***************************************************************************
*/

#include<stdio.h>
#include<string.h>
#include "bignum.h"

int stringtonum(char *s)
{
  int len=strlen(s),val=0,i=0;
  while(i<len)
  {
    val=val*10+s[i]-'0';
    i++;
  }
  return val;
}
//function to calculate phi(n)
int phi(int n)
{
    float result = n;
    for (int p=2; p*p<=n; ++p)
    {
        if (n % p == 0)
        {
            while (n % p == 0) n /= p;
            result *= (1.0 - (1.0 / (float) p));
        }
    }
    if (n > 1)
    {
          result *= (1.0 - (1.0 / (float) n));
          printf("%f\n",result);
    }
    return (int)result;
}
void main()
{
  int i=0;
  char s[5500],s1[5500],s2[100],s3[100];//some strings to handle bignum
  int val=1;//to store 5 power 10
  int phim,b=7830447,c,temp;
  for(i=0;i<10;i++) val*=5;//calculated 5^10
  phim=phi(val);//calculates phi(m) and store it in phim
  b=b%phim;//find remainder of b when divided  phim so we can solve the problem easily
  xpowery(s,2,b);//calculate 2 power b and stores in s
  strcpy(s1,s);
  dividestring(s,val);//divide 2^b with val
  strrev(s);
  multiplystring(s,val);// this is to get remainder
  /*
      let x=(2^b)
      what i did is x/(5^10) produces a integer value y
      which when multiplied by 5^10 produces some value z
      x-z is remainder when x/(5^10)
  */
  strrev(s);
  strrev(s1);
  i=0;
  int k=strlen(s),flag=1,j=0;
  while(i<k)
  {
    if(flag)
    {
      if(s[i]!=s1[i])
      {
        s2[j]=s[i];
        s3[j]=s1[i];
        flag=0;
        j++;
      }
    }
    else
    {
      s2[j]=s[i];
      s3[j]=s1[i];
      j++;
    }
    i++;
  }
  s2[j]='\0';
  s3[j]='\0';
  int ab=stringtonum(s3),cd=stringtonum(s2);
  unsigned long long int result,tvl=10000000000;
  result=(ab-cd);
  result*=1024;
  result%=tvl;
  result*=28433;
  result%=tvl;
  result++;
  result%=tvl;
  printf("%llu\n",result);
}
