/*
https://www.hackerrank.com/contests/codestorm-1-1/challenges/suzes-chocolate-story
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

char stack[150];
int top=-1;
char pop()
{
	if(top!=-1)
	{
		return stack[top--];
	}
	return -1;
}

void push(char ch)
{
	stack[++top]=ch;
}

int main()
{
    char s[110],ch;
    int i;
    scanf("%s",s);
    for(i=0;s[i]!=0;i++)
    {
        if(s[i]=='['||s[i]=='{'||s[i]=='(') push(s[i]);
        else if(s[i]==']'||s[i]=='}'||s[i]==')')
        {
            ch=pop();
            if(s[i]==']')
            {
                if(ch!='[')
                {
                    printf("Not Balanced\n");
                    return 0;
                }
            }
            else if(s[i]==')')
            {
                if(ch!='(')
                {
                    printf("Not Balanced\n");
                    return 0;
                }
            }
            else if(s[i]=='}')
            {
                if(ch!='{')
                {
                    printf("Not Balanced\n");
                    return 0;
                }
            }
        }
    }
    printf("Balanced\n");
    return 0;
}
