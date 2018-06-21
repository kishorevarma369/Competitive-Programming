#include<stdio.h>
#include<string.h>

int main(int argc, char const *argv[])
{
  int k,plen,qlen,i,j;
  char p[100],q[100];
  scanf("%s\n%s",p,q);
  scanf("%d",&k);
  plen=strlen(p);
  qlen=strlen(q);
  if(plen+qlen<=k)
  {
    printf("Yes\n");
    return 0;
  }
  for(i=0;p[i]!=0&&q[i]!=0;i++)  if(p[i]!=q[i]) break;
  if(p[i]==0) j=qlen-i;
  else if(q[i]==0) j=plen-i;
  else j=plen+qlen-2*i;
  if(j<=k)
  {
    if(j==k) printf("Yes\n");
    else if((j-k)%2==0) printf("Yes\n");
    else printf("No\n");
  }
  else printf("No\n");
  return 0;
}
