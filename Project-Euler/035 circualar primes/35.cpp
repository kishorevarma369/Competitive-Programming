/*

       --------------------written by KISHORE VARMA-------------------------------

       **************************************************************************
       circular primes                                             Problem 35

       The number, 197, is called a circular prime because all rotations of the
       digits: 197, 971, and 719, are themselves prime.

        There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37,
        71, 73, 79, and 97.

        How many circular primes are there below one million?

                   answer is                  55
                                ------------------------------------

       *************************************************************************
    ideas :-

        1) generate primes in seive method .
           lets assume that all numbers are prime and assign value 1(TRUE) for all >=2
           since 2 is prime its multiples will not be prime
                i.e., 4,8,16,32,................ set primeno[primepos]=0;
            now 3 has 1 so do the same job as above.
            4 is not a prime skipped
            primeno[5] is 1 so do the same as done with 2

            ..........proceed................
        2) all single digit numbers are circular primes so count them first
           and our logic will start from 10 onwards i.e., a 2 digit number
        3) we loop through all numbers and check
           if it is a prime then :
                    we simply find the circular notations and check if all its
                    circular permutations are prime ,
                    if all are prime then we will have n numbers for n-digit input .
                    we will add it to count . only if all digits are not same ,
                    else 1 is added .

        Note : once we find out circualr permutations of a prime number we can simply set it 0
        to avoid recalculations .
        thats it we are ready to solve this Problem :)

      ***************************************************************************
      --------------------written by KISHORE VARMA-------------------------------
      ***************************************************************************
*/
#include<iostream>
#define million 1000000
using namespace std;
bool prime[million];

void primegen()
{
  int i=0,j,k;
  for (i=2; i<million; i++) prime[i]=1;
  for(i=2;i<million;i++)
  {
    if(prime[i])
    {
      for (j=2; (k=i*j) < million; j++) prime[k]=0;
    }
  }
}

int main(int argc, char const *argv[])
{
  primegen();
  int i,j,k,dig=1,divi=1,ndivi=10,mat[6],l,m,flag,count=0;
  for(i=0;i<10;i++) if(prime[i]) count++;
  for(;i<1000000;i++)
  {
    if(i==ndivi)
    {
      dig++;
      divi=ndivi;
      ndivi*=10;
    }
    if(prime[i])
    {
      j=k=i;
      l=flag=0;
      while(j>9)
      {
        k=((k%divi)*10+k/divi);
        if(k==i) goto a; // making sure whether the given number has all digits same
        if(prime[k]) mat[l++]=k;
        else mat[l++]=0;
        j/=10;
      }
      for(m=0;m<l;m++)
      {
        prime[mat[m]]=0;
        if(!mat[m]) flag=1;
      }
      if(flag==0) count+=dig;
      continue;
      a:
      count+=1;
    }
  }
  cout<<count;
  return 0;
}
