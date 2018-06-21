/*
  such a wonderful question . i missed the logic in diagonal part.
  hint:each coin has 2 sides. //ly for diagonals
     X
*/

#include<stdio.h>
#define dcon 4
int main(int argc, char const *argv[])
{
  int a[20][20],i=0,j=0,k=0,l,m,p,q,tprod=1;
  long long int lprod=0;
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
  for (j=0; j<17; j++)
  {
    q=16-j;
    for (i=0; i<=q; i++) //20-4
    {
        m=j+i;
        l=i;
        tprod=1;
        for(k=0; k<4; k++)
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
  for (j=0; j<17; j++)
  {
    q=16-j;
    for (i=0; i<=q; i++) //20-4
    {
        m=j+i;
        l=j;
        tprod=1;
        for(k=0; k<4; k++)
        {
          tprod*=a[m][l];
          l++;
          m++;
        }
        if(tprod>lprod)
        {
          lprod=tprod;
        }
    }
  }
  for (j=19; j>=3; j--)
  {
    q=j-4;
    for (i=0; i<=q; i++) //20-4
    {
        m=j-i;
        l=i;
        tprod=1;
        for(k=0; k<4; k++)
        {
          tprod*=a[l][m];
          l++;
          m--;
        }
        if(tprod>lprod)
        {
          lprod=tprod;
        }
    }
  }
  for (i=0; i<=16; i++)
  {
    for (j=19; j>=3+i;j--) //20-4
    {
        m=j-i;
        l=i;
        tprod=1;
        for(k=0; k<4; k++)
        {
          tprod*=a[l][m];
          l++;
          m--;
        }
        if(tprod>lprod)
        {
          lprod=tprod;
        }
    }
  }
  printf("%lld\n",lprod);
  return 0;
}
