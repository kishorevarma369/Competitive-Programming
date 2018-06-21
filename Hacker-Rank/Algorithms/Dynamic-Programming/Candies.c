#include<stdio.h>

/*
  time limit exceeded solution:
    only 1 test case failed .

int main(int argc, char const *argv[])
{
  unsigned long long int sum=0;
  int n,i,flag,m=0;
  scanf("%d",&n);
  int rating[n],choc[n];
  scanf("%d",rating);
  choc[0]=1;
  for(i=1;i<n;i++)
  {
    scanf("%d",rating+i);
    if(rating[i]>rating[i-1])
    {
      choc[i]=choc[i-1]+1;
    }else choc[i]=1;
  }
  while(1)
  {
    //printf("%d\n",m++);
    flag=1;
    for(i=0;i<n-1;i++)
    {
      if(rating[i]<rating[i+1])
      {
        if(choc[i]>=choc[i+1])
        {
          flag=0;
          choc[i+1]=choc[i]+1;
        }
      }
      else if(rating[i]>rating[i+1])
      {
        if(choc[i]<=choc[i+1])
        {
          flag=0;
          choc[i]=choc[i+1]+1;
        }
      }
    }
    if(flag) break;
  }
  for(i=0;i<n;i++) sum+=choc[i];
  printf("%llu",sum);
  return 0;
}
*/

#define max(a,b) a>b?a:b

int main(int argc, char const *argv[])
{
  unsigned long long int sum=0;
  int n,i,flag,m=0;
  scanf("%d",&n);
  int rating[n],choc_left[n],choc_right[n];
  for(i=0;i<n;i++) scanf("%d",rating+i),choc_left[i]=choc_right[i]=1;
  for(i=1;i<n;i++)
  {
    if(rating[i-1]<rating[i]) choc_left[i]=1+choc_left[i-1];
  }
  for(i=n-1;i>0;i--)
  {
    if(rating[i-1]>rating[i]) choc_right[i-1]=1+choc_right[i];
  }
  for(i=0;i<n;i++) sum+=max(choc_left[i],choc_right[i]);
  printf("%llu",sum);
  return 0;
}
