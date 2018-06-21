/*

       --------------------written by KISHORE VARMA-------------------------------

       **************************************************************************
       Largest palindrome product                                       Problem 4

       A palindromic number reads the same both ways. The largest palindrome made from
       the product of two 2-digit numbers is 9009 = 91 × 99.

       Find the largest palindrome made from the product of two 3-digit numbers.

                   answer is                 906609
                                ------------------------------------

       *************************************************************************
    ideas :-

        1)  since we want to find largest product a*b which is pallindrome
            that is possible when we start with 999 which is largest three digit
            number and //ly for b

        2)  use a function pal that says whether a number is pallindrome or not

            fix i=999 and iterate till 100
              then fix j =i
                  if i*j is pallindrome -> got the answer
                  else j is decremented


        thats it we are ready to solve this Problem :)

      ***************************************************************************
      --------------------written by KISHORE VARMA-------------------------------
      ***************************************************************************
*/
#include<stdio.h>

int pal(int n)
{
  int j=n,num=0;
  while(n!=0)
  {
    num=num*10+n%10;
    n/=10;
  }
  if(j==num) return 1;
  return 0;
}

int main()
{
  int num=0;
  for(int i=999;i>100;i--)
  {
    for(int j=i;j>100;j--)
    {
      if(pal(i*j))
      {
        if(i*j>num) num=i*j;
        break;
      }
    }
  }
  printf("%d\n",num);
  return 0;
}
