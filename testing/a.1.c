#include<stdio.h>
#include<stdlib.h>

typedef void (*funptr)(int);
typedef void (*afunptr)();

int *gp; //global pointer to p

funptr myfun(int x)
{
    static int test=0;
    int p=x;
    void fun(int y)
    {
        printf("-----------------------\n");
        printf("\t  Test %d\n",test++);
        printf("address of global p: %x \n",gp);
        printf("address of p: %x \n",&p);
        printf("-----------------------\n");
        if(p<0)
        {
            printf("old p:%d\n",p);
            p=p+y;
            printf("new p:%d\n",p);
        }
        else
        {
            printf("old p:%d\n",p);
            p=p+y;
            printf("new p:%d\n",p);
        }
        printf("\n\n");
    }
    //asigning myfun_p for testing
    /*
        we all know variables are created by leaving some block of memory on stack
        before executing the code statements and are gone when function completes its 
        execution , but here something fishy is happening .
    */
    gp=&p;
    return fun;
} 

void some_fun()
{
    int a[100];
    for(unsigned int i=0;i<100;i++) a[i]=0;
    printf("stack created addresses are\n");
    printf("start : %x\n",a);
    printf("end : %x\n",a+99);
    //just clearing stack
}

int main(int argc, char const *argv[])
{
    funptr myptr=myfun(-5);
    myptr(8);
    printf("%x\n",myptr);
    some_fun();//creates large chunk on stack to make sure everything got cleared
    printf("returened back\n");
    myptr(-58);
    myptr(8);
    return 0;
}
