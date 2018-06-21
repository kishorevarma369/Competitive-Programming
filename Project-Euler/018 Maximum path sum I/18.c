#include<stdio.h>

int main(int argc, char const *argv[])
{
  FILE * fp =fopen("data.txt","r");
  if(fp==NULL)
  {
    printf("put data in a file and place it current folder \n");
    return 0;
  }
  int i=0,j,arr[121],n=15;
  while(fscanf(fp,"%d",arr+i)==1) i++;
  i--;
  for (l=n; l>0;l--)
  {
    k=i-l;
    for (j=i-2*l+1;j<i-l; j++)
    {
        if(arr[j]+arr[k]>arr[j]+arr[k+1]) arr[j]+=arr[k];
        else arr[j]+=arr[k+1];
        k++;
    }
    i-=l;
  }
  fclose(fp);
  return 0;
}
