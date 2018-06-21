/*

       --------------------written by KISHORE VARMA-------------------------------

       **************************************************************************
       Counting summations                                             Problem 76

       It is possible to write five as a sum in exactly six different ways:

                               4 + 1
                               3 + 2
                               3 + 1 + 1
                               2 + 2 + 1
                               2 + 1 + 1 + 1
                               1 + 1 + 1 + 1 + 1

       How many different ways can one hundred be written as a sum of at least two
       positive integers?

                   answer is                 190569291
                                ------------------------------------

       *************************************************************************
    comment :- one of the awesome questions i had ever seen
    ideas :-
          1) need to use recursion
          2) how to find the base case
          3) unlike asked in the question we are going to include n as well

                we are going to do like this

                  1 + 1 + 1 + 1 + 1
                  2 + 1 + 1 + 1
                  2 + 2 + 1
                  3 + 1 + 1
                  3 + 2
                  4 + 1
                  5
          explaination:-

                lets say we have 1+1+1+1...+1 (n 1's)
                it can be written as sum of 2's in n/2 ways (all terms are <=2)

                        ->  why we are taking all terms less than some val is because
                            to avoid repititions

            =>    if we have 3 then 3+1+1+1+..(n-3 1's) (all terms are <=3 )

                        ->  these 1's can be expressed as sum of 2's and 1's
                            or 3's,2's,1's

                      the problem appeared again 1+1+1....(n-3 1's) can be expressed
                      as sum of 2's (2<=3)

          1->                    1+1+1+...  -> 1 way

              [[[[[[[
                      <---simply solved by formula---> for some val if it is 2

              2->     we know that these can be expressed as sum of 2's in n/2 ways
                      2+1+1+...
                      2+2+1+...
                      ........
                      and finally
                      2+2+2+....(+1 if number is odd else +2 is last term)

             ]]]]]]]]
                      now can take 3 (as 3<=3)

          3->        3+1+1+1.....
                       \___________/
                            |
                      we call the problem again to solve sub problem

                            1+1+1+.. can be expressed as sum of 2's **goto 2->step

                            since no of ways using sum of 2's is done

                            we proceed to next step
                            3+1+1+....
                              \___________/
                                   |
                                   again sub problem do it with 1-> step

                        now,

                          we have

                              3+3+1+1...
                                  \___________/
                                       |
                                       again sub problem do it with 1-> step

                      this process repeats for any number of 1's

            example:=    takes sum as input here( n=8 ) max value it can go is upto 8

                              1 + 1 + 1 + 1 + 1 + 1 + 1 + 1

                    since it can go upto 8 i can loop from 2 - 8

                      i=2 =>
                              sub problem is 1 + 1 + 1 + 1 + 1 + 1

                              2 + [ 1 + 1 + 1 + 1 + 1 + 1  ]    -> 1 way

                              [ 2 + 1 + 1 + 1 + 1      ]   |=====\
                              [ 2 + 2 + 1 + 1          ]  |      /   no of ways is 6/2
                              [ 2 + 2 + 2              ] |=====/

                        i=3 =>

                            3 + [ 1 + 1 + 1 + 1 + 1 ]
                                --------------------
                                        |-> sub problem is 1 + 1 + 1 + 1 + 1

                                        this can be written as

                              [ 1 + 1 + 1 + 1 + 1  ]    -> 1 way

                              [ 2 + 1 + 1 + 1      ]
                              [ 2 + 2 + 1          ]  ||=====>   no of ways is 5/2

                              now take 3

                              [3 + 1 + 1 ]
                                   \____/
                                      \-> sub problem

                                      1+1 -> 1 way
                                      2 -> 1 way

                        we completed for i=2,3 //ly do it for 4,5,6,7,8

        thats it we are ready to solve this Problem :)

      ***************************************************************************
      --------------------written by KISHORE VARMA-------------------------------
      ***************************************************************************
*/

#include<stdio.h>
#define val 100
int total=0;//to count no of ways
void fun(int sum,int va)
{
  // va is 2 then i can express the sum only using 1 or 2
  if(va==2)
  {
    total+=1+sum/2;
    return;
  }
  else
  {
    total++;
    for(int i=2;i<=va&&sum-i>=0;i++) fun(sum-i,i);
  }
}

void main()
{
  fun(val,val);
  printf("%d\n",total-1);
  //total-1 to exclude the number val i.e., 100
}
