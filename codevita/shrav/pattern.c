#include<stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  char ans[101][99999];
  int n,val=10;
  char buffer[100000];
  scanf("%d",&n);
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<2*i;j++) ans[i][j]='*';
    ans[i][2*i]=0;
   	for(int j=0;j<n-i;j++)
    {
      	sprintf(buffer,"%d",val);
     	strcat(ans[i],buffer); 
      	val=val+10;
    }
  }
  for(int i=n-1;i>=0;i--)
  {
   	for(int j=0;j<n-i;j++)
    {
     	sprintf(buffer,"%d",val);
     	strcat(ans[i],buffer); 
      	val=val+10;
    }
  }
  for(int i=0;i<n;i++)
  {
    int k=strlen(ans[i]);
    ans[i][k-1]=0;
    printf("%s\n",ans[i]);
  }
  return 0; 
}