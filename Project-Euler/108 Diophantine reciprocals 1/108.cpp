/*

       --------------------written by KISHORE VARMA-------------------------------

       **************************************************************************
       Diophantine reciprocals I                                      Problem 108

       In the following equation x, y, and n are positive integers.

                            1   1     1
                            - + -  =  -
                            x   y     n

       For n = 4 there are exactly three distinct solutions:

       What is the least value of n for which the number of distinct solutions exceeds
       one-thousand?
       NOTE: This problem is an easier version of Problem 110; it is strongly advised
       that you solve this one first.

                   answer is                  709
                                ------------------------------------

       *************************************************************************
    ideas :-

       1) dividing the equation with y would result in n(x/y+1)=x

              n(t+1)=ty        ->  assume x/y=t
              n=t(y-n)         ->  on rewriting
              n=uv             -> assume u=t and v=y-n

              now the problems is entirely changed

              we have n

                        we need to find v by fixing u
                                    or
                        we need to find v by fixing u

              no of (u,v) pairs is simply = number of divisors of n

                  for n=4 (u,v) pairs are (1,4) (2,2) (4,1)
                  simply u={1,2,4}

              so we need to find number of divisors of n which is
                n=2^a * 3^b * ..... k^l where k is prime number and l is constant
                no of divisors of n is (a+1)*(b+1)*...*(l+1)

        thats it we are ready to solve this Problem :)

      ***************************************************************************
      --------------------written by KISHORE VARMA-------------------------------
      ***************************************************************************
*/
#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
int main(int argc, char const *argv[])
{
  int n=1260,i,count;
  //for(n=4;count<100;n++)
  {
    count=0;
    for (i = 1; i*i<=n; i++)
    {
      if(n%i==0)
      {
        count++;
        printf("\t%d %d\n",n+i,((n+i)*n)/i);
      }
    }
    system("pause");
  }
  printf("\n%d %d\n",n,count);
  return 0;
}
