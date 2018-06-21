#include<stdio.h>

int main(int argc, char const *argv[])
{
  FILE * fp=fopen("triangles.txt","r");
  if(fp==NULL)
  {
    printf("Not okay");
    return 1;
  }
  int x1,y1,x2,y2,x3,y3;//for co-ordinates
  int counter,res=0;
  while(fscanf(fp,"%d,%d,%d,%d,%d,%d\n",&x1,&y1,&x2,&y2,&x3,&y3)==6)
  {
    counter=0;
    if(x1*y2>x2*y1) counter++;
    else counter--;
    if(x2*y3>x3*y2) counter++;
    else counter--;
    if(x3*y1>x1*y3) counter++;
    else counter--;
    if(counter==3||counter==-3) res++;
  }
  printf("result is %d\n",res);
  return 0;
}
