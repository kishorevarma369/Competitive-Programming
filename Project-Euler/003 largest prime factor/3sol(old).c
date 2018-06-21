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

           "think yourself and understand this" 

        thats it we are ready to solve this Problem :)

      ***************************************************************************
      --------------------written by KISHORE VARMA-------------------------------
      ***************************************************************************
*/
#include <stdio.h>
#include <math.h>
#include<stdlib.h>
#define kil 1000000
// 600,851,475,143
int main()
{
    int i,prime=1,j=0,l=0,k=0;
    int *a=(int *)malloc(kil*sizeof(int));
    int *b=(int *)malloc(10000*sizeof(int));
    //stack cant hold more than 1 million items
    unsigned long long lov=600851475143;
    a[j++]=2;
    if(lov%a[j-1]==0) b[k++]=a[j-1];
    for(i=3;i<sqrt(lov);i++)//sqrt(lov)
    {
      prime=1;
      for(l=0;a[l]<=sqrt(i)&&l<j;l++)
      {
        if(i%a[l]==0)
        {
          prime=0;
          break;
        }
      }
      if(prime) {
        a[j++]=i;
        if(lov%a[j-1]==0){
          b[k++]=a[j-1];
        }
      }
      if(a[j-1]>sqrt(lov)&&k==0) break;
    }
    if(k==0) printf("%llu\n",lov);
    else printf("Largest prime factor is %d\n",b[k-1]);
    for(i=0;i<k;i++) printf("%d\n",b[i]);
    free(a);
    free(b);
    return 0;
}
