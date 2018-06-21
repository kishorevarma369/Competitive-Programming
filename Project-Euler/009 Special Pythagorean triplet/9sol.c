/*

       --------------------written by KISHORE VARMA-------------------------------

       **************************************************************************
       Special Pythagorean triplet                                     Problem 9

       A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,

                  a^2 + b^2 = c^2

              For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.

        There exists exactly one Pythagorean triplet for which a + b + c = 1000.

        Find the product abc.

                   answer is                  31875000
                                ------------------------------------

       *************************************************************************
    ideas :-

        1)  since a^2+b^2=c^2 and also a+b+c=1000

          a+b=1000-c squaring on both sides we get the result on simplifying

              ab=1000(500-c) -> c cant be greater than 500

        therefore a<b<c<500 c has maxmium value so

                  c is started from 499..1
                  b is strated from c-1 .... 1 and also (1000-c-b)<b


        thats it we are ready to solve this Problem :)

      ***************************************************************************
      --------------------written by KISHORE VARMA-------------------------------
      ***************************************************************************
*/

#include<stdio.h>

void main()
{
  int c,a,b,temp;
  for(c=499;c>0;c--)
  {
    for(b=c-1;b>0;b--)
    {
      a=1000-b-c;
      if(a>b) break;
      if((b*b+a*a)==(c*c)) goto key;
    }
  }
  //lazy to use another variable (flag) in order get out when we get result so used goto statement
  key:
  printf("%d\n",1000*(500-c)*c);
}
