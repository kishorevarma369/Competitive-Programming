/*

       --------------------written by KISHORE VARMA-------------------------------

       **************************************************************************
       10001st prime                                                   Problem 7

       By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see
       that the 6th prime is 13.

       What is the 10 001st prime number?

                   answer is                 104743
                                ------------------------------------

       *************************************************************************
    ideas :-

        1)  store all prime numbers generated in an array

        2)  generate till i found 10001st prime

        3) a number can be said as a prime if any prime less than sqrt(n) doesn't
           divide it.

              i.e., lets say number is 5
              primes less than 5 is 2,3 and sqrt(5) will be around 2.xyz..
              5 cant be divided so its a prime.

            by this method we reduce our checking significantly

            however sqrt(n) is a heavy function and takes quite some time.
            in order to reduce time consumption we change

                          a[i]<=sqrt(n) -> a[i]*a[i]<=n

        thats it we are ready to solve this Problem :)

      ***************************************************************************
      --------------------written by KISHORE VARMA-------------------------------
      ***************************************************************************
*/

#include <stdio.h>
//give k value here to get all 10001 primes
#define k 10001
int main()
{
    int a[k],n,num,i,j=0,prime;
    //i started storing from index 0 so 1st prime becomes 0th prime
    a[j++]=2;
    for(n=3;j<k;n++)
    {
        prime=1;
        for(i=0;a[i]*a[i]<=n;i++)
        {
            if(n%a[i]==0){
                prime=0;
                break;
            }
        }
        if(prime==1) a[j++]=n;
    }
    // to get 10001st prime i need to get to 10000th prime in array
    printf("%d\n",a[k-1]);
    return 0;
}
