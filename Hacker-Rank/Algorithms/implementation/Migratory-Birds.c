#include<stdio.h>

int main(int argc, char const *argv[])
{
  int n,i,index[6]={0},maxfreq=0,maxid=0;
  scanf("%d",&n);
  int a[n];
  for(i=0;i<n;i++)
  {
    scanf("%d",a+i);
    index[a[i]]++;
  }
  for(i=1;i<=5;i++)
  {
    if(index[i]>maxfreq){
      maxfreq=index[i];
      maxid=i;
    }
  }
  printf("%d\n",maxid);
  return 0;
}
