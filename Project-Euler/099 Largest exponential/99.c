/*

       --------------------written by KISHORE VARMA-------------------------------

       **************************************************************************
       Largest exponential                                              Problem 99

        Comparing two numbers written in index form like 211 and 37 is not difficult,
        as any calculator would confirm that 211 = 2048 < 37 = 2187.However, confirming
        that 632382518061 > 519432525806 would be much more difficult, as both numbers
        contain over three million digits.Using base_exp.txt (right click and 'Save
        Link/Target As...'), a 22K text file containing one thousand lines with a
        base/exponent pair on each line, determine which line number has the greatest
        numerical value.
        NOTE: The first two lines in the file represent the numbers in the example
        given above.

                   answer is                  709
                                ------------------------------------

       *************************************************************************
    ideas :-

        1) making the exponent smaller .possibilities are by dividing it .
        but with which number ? so i need to find the smallest number for exponent.
        not so good.
        2)  use basic log just as we do in math for comparision
            a^b>c^d
            b*log(a)>d*log(c) (on applying logarithms on both sides)

          in c we can use log10 function which helps in finding logarithm values
          of base 10

        thats it we are ready to solve this Problem :)

      ***************************************************************************
      --------------------written by KISHORE VARMA-------------------------------
      ***************************************************************************
*/

#include<stdio.h>
#include<math.h>
int main()
{
  //get data from FILE and doing operations at same time
  FILE *fp=fopen("data.txt","r");
  int base=0,expo=0,lno=0,llno=0;
  long double lprod=0,temp=0;
  while(fscanf(fp,"%d %d",&base,&expo)==2&&++lno)//making sure that scan is succesfull
  {
    temp=expo*log10(base);
    if(lprod<temp)
    {
      lprod=temp;
      llno=lno;
    }
  }
  printf("%d\n",llno);
  return 0;
}
