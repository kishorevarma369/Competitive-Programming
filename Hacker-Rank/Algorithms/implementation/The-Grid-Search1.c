#include<stdio.h>
#include<string.h>
void fun()
{
  int m,n,p,q,i,j,k,l,u,v;
  scanf("%d %d",&m,&n);
  char s[m][n],*o;
  for(i=0;i<m;i++) scanf("%s",s[i]);
  scanf("%d %d",&p,&q);
  char t[p][q];
  for(i=0;i<p;i++) scanf("%s",t[i]);
  for(i=0;i<m;i++)
  {
    j=0;
      o=strstr(s[i],t[j]);
      while(o)
      {
        o+=n;
        o=strstr(o,t[j+1])s
      }

  }
  printf("NO\n");
}

int main(int argc, char const *argv[])
{
  int n;
  scanf("%d",&n);
  while(n--) fun();
  return 0;
}
