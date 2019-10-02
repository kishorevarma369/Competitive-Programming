#include<bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int n,p;
    cin>>n>>p;
    int mymax=0,mycount=p*p,val,val1,val2;
    for(int i=2;i<=p;i++)
    {
        val=n%i;
        if(val>=mymax){
            //handle less
            for(int j=1;j<val;j++)
            {
                val1=val%j;
                if(val1>=mymax)
                {
                    for(int k=1;k<val1;k++)
                    {
                        val2=(val1%k)%n;
                        if(val2>mymax)
                        {
                            mycount=1;
                            mymax=val2;
                        }
                        else if(val2==mymax) mycount++;
                    }
                    if(val1<p)
                    {
                        if((val1%n)==mymax)
                        {
                            mycount+=(p-val1-1);
                        }
                        else if((val1%n)>mymax){
                            mycount=1;
                            mymax=val1%n;
                        }
                    }
                    

                }
            }
            for(int j=val+1;j<=p;j++)
            {
                val1=val%j;
            }
        }
        
    }
    return 0;
}
