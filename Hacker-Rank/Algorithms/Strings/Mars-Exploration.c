#include<stdio.h>

int main(int argc, char const *argv[])
{
  int count=0;
  char a,b,c;
  while(1)
  {
      c=getchar();
      if(c==-1) break;
      if(c!='S') count++;
      if(getchar()!='O') count++;
      if(getchar()!='S') count++;
  }
  printf("%d\n",count);
  return 0;
}
