/*
//efficent but fails one test case
//so brute force is preffered.
#include<stdio.h>
int gcd(int a, int b)
{
    if (a == b) return a;
    if (a > b) return gcd(a-b, b);
    return gcd(a, b-a);
}

int lcm(int a, int b)
{
    return (a*b)/gcd(a, b);
}

int main(int argc, char const *argv[])
{
  int m,n,i,j,k=0,l=1,count=0;
  scanf("%d %d",&m,&n);
  int a[m],b[n];
  for(i=0;i<m;i++)
  {
    scanf("%d",a+i);
    l=lcm(l,a[i]);
  }
  scanf("%d",b);
  k=b[0];
  for(i=1;i<n;i++)
  {
    scanf("%d",b+i);
    k=gcd(k,b[i]);
  }
  printf("\nk\n");
  for(i=l;i<=k;i+=l)
  {
    if(k%i==0) count++;
  }
  printf("%d\n",count);
  return 0;
}
*/

#include<stdio.h>

int main()
{
  int m,n,i,j,k,amax=0,bmin=101,count=0;
  scanf("%d %d",&m,&n);
  int a[m],b[n];
  for(i=0;i<m;i++)
  {
    scanf("%d",a+i);
    if(amax<a[i]) amax=a[i];
  }
  for(i=0;i<n;i++)
  {
    scanf("%d",b+i);
    if(bmin>b[i]) bmin=b[i];
  }
  for(i=amax;i<=bmin;i++)
  {
    for(j=0;j<m;j++) if(i%a[j]!=0) break;
    if(j!=m) continue;
    for(j=0;j<n;j++) if(b[j]%i!=0) break;
    if(j!=n) continue;
    count++;
  }
  printf("%d\n",count);
  return 0;
}
