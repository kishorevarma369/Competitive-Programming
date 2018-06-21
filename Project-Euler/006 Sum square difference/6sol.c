/*

       --------------------written by KISHORE VARMA-------------------------------

       **************************************************************************
       Sum square difference                                            Problem 6

       The sum of the squares of the first ten natural numbers is,

                  1^2 + 2^2 + ... + 10^2 = 385

       The square of the sum of the first ten natural numbers is,

                  (1 + 2 + ... + 10)^2 = 55^2 = 3025

        Hence the difference between the sum of the squares of the first ten natural
        numbers and the square of the sum is 3025 − 385 = 2640.

        Find the difference between the sum of the squares of the first one hundred
        natural numbers and the square of the sum.

                   answer is                 25164150
                                ------------------------------------

       *************************************************************************
    ideas :-

        1)  1+2+3+..n = n(n+1)/2
        2)  1^2 + 2^ +.....+n^2 = n(n+1)(2n+1)/6

        thats it we are ready to solve this Problem :)

      ***************************************************************************
      --------------------written by KISHORE VARMA-------------------------------
      ***************************************************************************
*/
#include<stdio.h>
#define k 100
void main()
{
  int sum=(k*(k+1))/2,sumofsquares=(k*(k+1)*(2*k+1))/6;
  printf("%d\n",sum*sum-sumofsquares);
}
