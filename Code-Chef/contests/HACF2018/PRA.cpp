#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX_PRIME 1000001

int primeno[MAX_PRIME];

void primegen()
{
  primeno[2]=1;
  primeno[0]=primeno[1]=0;
  int i,j;
  for(i=3;i<MAX_PRIME;i+=2) primeno[i]=1;
  for(i=3;i<MAX_PRIME;i+=2)
  {
    if(primeno[i])
    {
      for(j=2*i;j<MAX_PRIME;j+=i) primeno[j]=0;
    }
  }
  for(i=1;i<MAX_PRIME;i++)
  {
    primeno[i]+=primeno[i-1];
  }
}

int main(int argc, char const *argv[])
{
  int n,beg,end,count;
  scanf("%d",&n);
  primegen();
  while(n--)
  {
    scanf("%d %d",&beg,&end);
    if(beg==0) count=primeno[end];
    else count=primeno[end]-primeno[beg-1];
    if(count<=0) printf("%.6f\n",0);
    else printf("%.6f\n",float(count)/(end-beg+1));
  }

  return 0;
}
