/*

      Question :-

          https://www.hackerrank.com/challenges/compare-the-triplets

      ***************************************************************************
      --------------------written by KISHORE VARMA-------------------------------
      ***************************************************************************
*/
#include <stdio.h>

int main()
{
    int a[3],b[3],ascore=0,bscore=0,i;
    for(i=0;i<3;i++) scanf("%d",a+i);
    for(i=0;i<3;i++) scanf("%d",b+i);
    for(i=0;i<3;i++)
    {
        if(a[i]>b[i]) ascore++;
        else if(b[i]>a[i]) bscore++;
    }
    printf("%d %d",ascore,bscore);
    return 0;
}
