#include<stdio.h>
#define dcon 4
int main(int argc, char const *argv[])
{
  int a[20][20],i=0,j=0,k=0,l,m,p,q,tprod=1,lprod=0;
  //getting data from file
  FILE *fp=fopen("data.txt","r");
  while(fscanf(fp,"%d",*a+i)==1) i++;
  fclose(fp);
  //data recieved so we can proceed
  //find largest product of consecutive elements in row
  for (j = 0; j<20; j++)
  {
    for (i = 0; i<=16; i++) //20-4
    {
      l=i+4;
      tprod=1;
      for (k = i; k<l; k++)
      {
        tprod*=a[j][k];
      }
      if(tprod>lprod)
      {
        lprod=tprod;
      }
    }
  }
  printf("%d\n",lprod);
  for (j = 0; j<20; j++)
  {
    for (i = 0; i<=16; i++) //20-4
    {
      l=i+4;
      tprod=1;
      for (k = i; k<l; k++)
      {
        tprod*=a[k][j];
      }
      if(tprod>lprod)
      {
        lprod=tprod;
      }
    }
  }
  printf("%d\n",lprod);
  for (j=0; j<20; j++)
  {
    q=20-j-4;
    printf("j=%d\n",j);
    for (i=0; i<=q; i++) //20-4
    {
      printf("\ti=%d\n",i);
      for (p = 0; p <=q; p++)
      {
        printf("\t\tp=%d\n",p);
        l=p+i;
        m=p+j;
        tprod=1;
        for (k=0; k<4; k++)
        {
          tprod*=a[l][m];
          l++;
          m++;
        }
        if(tprod>lprod)
        {
          lprod=tprod;
        }
      }
    }
  }
  printf("\n%d",lprod);
  return 0;
}
