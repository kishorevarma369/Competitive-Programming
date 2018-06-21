/*

  number is 1_2_3_4_5_6_7_8_9_0,
  last digit is zero and this number is a perfect square => last unknown digit is zero
  so lets get rid of last 2 digits

  new number is 1_2_3_4_5_6_7_8_9 .

  last digit is 9 , since its a perfect square it can be obtained if last digit is 3 or 7 .

  maximum possible value is 19293949596979899 lets find its square root , its value is 138902663
  let it be a . we want final a*a = 1_2_3_4_5_6_7_8_9 .
  make sure its last digit is 3 or 7 , by substarcting 6 , 4 consecutively .
  since we already know that last digit when squared is 9 and we don't care its preceeding number
  because its a _ .
  let i=8
  Now , we have , 1_2_3_4_5_6_7_8 check whether its last digit is i
      if so continue to check by decrementing i
  else break, because we didnt get what we wanted.

*/

#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
  char s[100];
  long long int a=138902663,k,l,i=8;
  while(1)
  {
    k=(a*a)/100,i=8;
    while(k!=0) if(k%10==i--) k/=100; else break;
    if(k==0) break;
    i=8,a-=6,k=(a*a)/100;
    while(k!=0) if(k%10==i--) k/=100; else break;
    if(k==0) break;
    a-=4;
  }
  cout<<a<<"0";//put zero at the end because last 2 digits is 0
  return 0;
}
