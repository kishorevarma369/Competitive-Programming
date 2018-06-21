#include<stdio.h>

int main(int argc, char const *argv[]) {
  int min,hrs;
  char *s[]={"","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","quarter","seventeen","eighteen","nineteen","twenty"};
  scanf("%d %d",&hrs,&min);
  if(min)
  {
      if(min==30)
      {
        printf("half past %s",s[hrs]);
      }
      else if(min<30)
      {
        if(min<=20)
        {
          if(min==1) printf("%s minute past %s",s[min],s[hrs]);
          else if(min!=15) printf("%s minutes past %s",s[min],s[hrs]);
          else printf("quarter past %s",s[hrs]);
        }
        else
        {
          min-=20;
          printf("twenty %s minutes past %s",s[min],s[hrs]);
        }
      }
      else
      {
          min=60-min;
          if(min<=20)
          {
            if(min==1) printf("%s minute past %s",s[min],s[hrs+1]);
            else if(min!=15) printf("%s minutes to %s",s[min],s[hrs+1]);
            else printf("quarter to %s",s[hrs+1]);
          }
          else
          {
            min-=20;
            printf("twenty %s minutes to %s",s[min],s[hrs+1]);
          }
      }
  }
  else
  {
    printf("%s o' clock",s[hrs]);
  }
  return 0;
}
