#include<stdio.h>

void fun()
{
  int i=0,j=0,k=0,index[26]={0},count=0,len;
  char s[100],h[100];
  scanf("%s",s);
  for(;s[i]!=0;i++)
  {
    index[s[i]-'a']++;
    if(index[s[i]-'a']==2) h[j++]=s[i],count++;
  }
  len=i;
  h[j]=0;
  for(k=2;k<len-1;k++)
  {
    for(i=0;i<=len-k;i+=k)
    {
      for(j=i+1;j<len;j++)
      {
        if(s[i]==s[j])
      }
    }
  }

}


int main(int argc, char const *argv[])
{
  int n;
  scanf("%d",&n);
  while(n--) fun();
  return 0;
}
