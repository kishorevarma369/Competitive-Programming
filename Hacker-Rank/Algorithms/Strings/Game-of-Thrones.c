#include<stdio.h>

int main(int argc, char const *argv[])
{
  int n,index[26],i,len,flag=0,k;
  char s[100000],prev,a,b;
  scanf("%s",s);
  for(i=0;i<26;i++) index[i]=0;
  for(i=0;s[i]!=0;i++) index[s[i]-'a']+=1;
  len=i;
  k=i&1;
  for(i=0;i<26;i++)
  {
    if(index[i]&1)
    {
      if(k==1)
      {
        flag++;
        if(flag==2) break;
      }
      else
      {
        flag=2;
        break;
      }
    }
  }
  if(flag==2) printf("NO\n");
  else printf("YES\n");
  return 0;
}
