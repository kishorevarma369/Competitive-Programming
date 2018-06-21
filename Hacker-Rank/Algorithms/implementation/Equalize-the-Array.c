#include<stdio.h>

int main(int argc, char const *argv[])
{
  int n,i,freq[101]={0},total=0,max=0;
  scanf("%d",&n);
  int arr[n];
  for(i=0;i<n;i++)
  {
    scanf("%d",arr+i);
    freq[arr[i]]++;
  }
  for(i=1;i<101;i++)
  {
    if(freq[i]>max) max=freq[i];
  }
  printf("%d",n-max);
  return 0;
}
