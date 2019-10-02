#include<stdio.h>
#include<stdlib.h>


int length(char number[])
{
    int i=0;
    while(number[i]) i++;
    return i;
}

void reverse(char *p,char *q)
{
    char t;
    while(p<q)
    {
        t=*p;
        *p=*q;
        *q=t;
        p++;
        q--;
    }
}
char base_array[]="0123456789abcdefghijklmnopqrstuvwxyz";
void convert(int no,int base,char number[])
{
    int i=0,tmp=no;
    while(tmp)
    {
        number[i++]=base_array[tmp%base];
        tmp/=base;
    }
    number[i]=0;
}



int let_find(char c)
{
    if (c >= '0'&&c <= '9'){
                return c-'0';
    }
    if (c >= 'a'&&c <= 'z'){
       return 10+c - 'a';
    }
    return 0;
}

char sumOfDigits(char number[], int base) {
	int t;
	int ans = 0,carry=0,pos;
    while(number[0]&&number[1])
    {
        ans=0;
        for (int i = 0; number[i]; i++)
        {
            ans+=let_find(number[i]);
        }
        convert(ans,base,number);
    }
    return number[0];
}

int main()
{
    int base = 2;
    char num[10] = { '1', '0', '1', '\0' };
    char expected = 'e';
    printf("%c",sumOfDigits(num,base));
    return 0;
}