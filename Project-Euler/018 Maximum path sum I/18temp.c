#include<stdio.h>

int main(int argc, char const *argv[])
{
  FILE * fp =fopen("data1.txt","r");
  if(fp==NULL)
  {
    printf("put data in a file and place it current folder \n");
    return 0;
  }
  int k,l,p,q,arr[11],n=4;
  while(fscanf(fp,"%d",arr+i)==1) ;
  i--;
  printf("k\n");
  for (l=n; l>0;l--)
  {
    q=(l-1)*(l-2);
    p=q-n-1;
    k=q;
    for (; p < k ; p++)
    {
      if(arr[q]>arr[q+1]) arr[p]+=arr[q];
      else arr[p]+=arr[q+1];
      q++;
    }
  }
  printf("%d",arr[0]);
  fclose(fp);
  return 0;
}
