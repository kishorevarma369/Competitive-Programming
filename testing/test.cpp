#include<bits/stdc++.h>

using namespace std;

int sod(int val)
{
    int ans=0;
    while(val)
    {
        ans+=val%10;
        val/=10;
    }
    return ans;
}

int main(int argc, char **argv)
{
    int n=1999,index=999;
    for(int i=9993;;i++)
    {
        if(sod(i)%10==0)
        printf("%d : %d \n",index++,i);
        if(index==n) break;
    }
    return 0;
}