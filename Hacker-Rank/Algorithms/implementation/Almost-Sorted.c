#include<stdio.h>

int issorted(int *a,int i,int j)
{
  int p=i+1,q=j-1;
  if(p>q) return 0;
  for(;p<q;p++) if(a[p]<a[p+1]) break;
  if(p==q) return 1;
  return 0;
}

int main(int argc, char const *argv[])
{
  int n,i,j,k,l;
  scanf("%d",&n);
  int a[n];
  for(i=0;i<n;i++) scanf("%d",a+i);
  j=i-1;
  for(i=0;i<n-1&&j>0;i++,j--)
  {
    if(a[i]>a[i+1])
    {
      for(;j>0;j--) if(a[j]<a[j-1]) break;
      break;
    }
    if(a[j]<a[j-1])
    {
      for(;i<n-1;i++) if(a[i]>a[i+1]) break;
      break;
    }
  }
  if(issorted(a,i,j))
  {
    if(a[i]<=a[j+1]&&a[j]>=a[i-1])
    {
      printf("yes\nreverse %d %d\n",i+1,j+1);
      return 0;
    }
  }
  else
  {
    k=i+1;
    l=j-1;
    for(;k<l;k++) if(a[k]>a[k+1]) break;
    if(k>=l)
    {
      if(a[i]>a[j])
      {
        if(a[i]>=a[j-1]&&a[i]<=a[j+1]&&a[j]>=a[i-1]&&a[j]<=a[i+1])
        {
          printf("yes\nswap %d %d\n",i+1,j+1);
          return 0;
        }
      }
    }
  }
  printf("NO\n");
  return 0;
}
