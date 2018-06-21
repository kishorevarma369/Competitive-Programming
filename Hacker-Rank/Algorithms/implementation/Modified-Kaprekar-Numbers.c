#include<stdio.h>

int main(int argc, char const *argv[])
{
  int p,q,i,j,k,l,m,arr[]={1,10,100,1000,10000,100000};
  scanf("%d %d",&p,&q);
  while(p%arr[i++]);
  for(i=p;i<q;i++)
  {
    k=i*i;
    m=k%l;
    k/=l;
    if(m+k==i) printf("%d ",i);

  }
  return 0;
}
