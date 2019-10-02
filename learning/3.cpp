#include<bits/stdc++.h>

using namespace std;
int n,a[50];

int LIS(int index,int val)
{
    int k=0,c=0;
    if(index<n)
    {
        if(val<a[index])
        {
            k=1+LIS(index+1,a[index]);

        }
        c=LIS(index+1,val);  
    }
    if(k>c)
    {
        return k;
    }
    return c;
}
int main()
{
    int i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    j=LIS(0,INT_MIN);
    printf("%d",j);
    return 0;
}