#include<stdio.h>

int main(int argc, char const *argv[])
{
  int n,index[26],i,j,k,len,maxlen=0,flag=0,count=0;
  scanf("%d",&n);
  char s[n],prev,a,b;
  scanf("%s",s);
  for (i = 0; i < 26; i++) index[i]=0;
  for(i=0;s[i]!=0;i++)
  {
    if(index[s[i]-'a']==0)
    {
      index[s[i]-'a']=1;
      count++;
    }
  }
  if(count<2){
    printf("0\n");
    return 0;
  }
  for(i=0;i<26;i++)
  {
    if(index[i]==0) continue;
    for(j=i+1;j<26;j++)
    {
      if(index[j]==0) continue;
      a='a'+i;
      b='a'+j;
      prev=-1;
      len=0;
      flag=1;
      for (k=0;s[k]!=0; k++)
      {
        if(s[k]==a||s[k]==b)
        {
          if(prev==-1) prev=s[k];
          else if(prev==s[k])
          {
              flag=0;
              break;
          }
          prev=s[k];
          len++;
        }
      }
      if(flag) if(len>maxlen) maxlen=len;
    }
  }
  printf("%d\n",maxlen);
  return 0;
}
