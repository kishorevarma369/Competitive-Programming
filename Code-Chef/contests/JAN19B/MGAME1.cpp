#include<bits/stdc++.h>

using namespace std;

int mymax=0,mycount,n,p;

void handler(int val,int level)
{
    int val1;
    if(level==3)
    {
        for(int i=1;i<val;i++)
        {
            val1=(val%i)%n;
            if(val1==mymax)
            {
                mycount++;
            }
            else if(val1>mymax)
            {
                mymax=val1;
                mycount=1;
            }
        }
        if((val%n)==mymax)
        {
            if(val<p) mycount+=p-val;
        }
        else if((val%n)>mymax){
            if(val<p) mycount=p-val;
        }
        return;
    }
    for(int i=1;i<val;i++)
    {
        val1=val%i;
        if(val1>=mymax)
        {
            handler(val1,level+1);
        }
    }
    if(val>=mymax) 
    {
        for(int i=val+1;i<=p;i++)
        {
            handler(val,level+1);
        }
    }
    
}

int main(int argc, char const *argv[])
{
    cin>>n>>p;
    mycount=p*p;
    handler(n,1);
    return 0;
}
