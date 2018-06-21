#include<stdio.h>
#include<string.h>
void fun()
{
  int m,n,p,q,i,j,k,l,u,v;
  scanf("%d %d",&m,&n);
  char s[m][n];
  char *a,*b;
  for(i=0;i<m;i++) scanf("%s",s[i]);
  scanf("%d %d",&p,&q);
  char t[p][q];
  for(i=0;i<p;i++) scanf("%s",t[i]);
  if(p>m||q>n)
  {
    printf("NO\n");
    return;
  }
  for(i=0;i<=m-p;i++)
  {
    for(j=0;j<=n-q;j++)
    {
      if(s[i][j]==t[0][0])
      {
        for(k=0;k<p;k++)
        {
          a=&s[k+i][j];
          b=&t[k][0];
          for(l=0;l<q;l++) if(*(a++)!=*(b++)) break;
          if(l!=q) break;
        }
        if(k==p)
        {
          printf("YES\n");
          return ;
        }
      }
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
