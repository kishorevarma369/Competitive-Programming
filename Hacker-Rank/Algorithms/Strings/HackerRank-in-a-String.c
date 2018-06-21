#include<stdio.h>

int main(int argc, char const *argv[])
{
  int n,i,j,k;
  char s[10000],str[20]="hackerrank";
  scanf("%d",&n);
  for (i = 0; i < n; i++)
  {
    scanf("%s",s);
    for (j=0,k=0;s[j]!=0; j++) {
      if(k>=10) break;
      if(s[j]==str[k]) k++;
    }
    if(k==10) printf("YES\n");
    else printf("NO\n");
  }
  return 0;
}
