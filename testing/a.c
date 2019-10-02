#include<stdio.h>
#include<stdlib.h>

typedef void (*funptr)(int);

funptr myfun(int x)
{
    int p=x;
    void fun(int y)
    {
        printf("old p:%d\n",p);
        p=p+y;
        printf("new p:%d\n",p);
        printf("\n\n");
    }
    return fun;
} 

int main(int argc, char const *argv[])
{
    funptr myptr=myfun(-5);
    myptr(8);
    funptr myptr1=myfun(100);
    myptr(3);
    myptr(8);
    return 0;
}
