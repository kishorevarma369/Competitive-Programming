#include<stdio.h>

int main(int argc, char const *argv[]) {
  char s[100000];
  int count=1,i=0;
  while (s[i]!=0)
  {
    if(s[i]>='A'&&s[i]<='Z') count++,i++;
  }
  printf("%d\n",count);
  return 0;
}
