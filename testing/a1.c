#include<stdio.h>

typedef void (*afunptr)();

afunptr fun()
{
    void main()
    {
        printf("hey , I am kishore and very good to see you \n");
    }
    return main;
}

int main()
{
    afunptr main=fun();
    main();
    return 0;
}
