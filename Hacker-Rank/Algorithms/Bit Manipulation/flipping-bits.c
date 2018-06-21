#include<stdio.h>

int main(int argc, char const *argv[]) {
  unsigned int n,i;
  scanf("%u",&n);
  while(n--)
  {
    scanf("%u",&i);
    printf("%u\n",~i);
  }
  return 0;
}
