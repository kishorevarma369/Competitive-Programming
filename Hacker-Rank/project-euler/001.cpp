#include <bits/stdc++.h>

using namespace std;

int main()
{
    long t,beg,end,tmpn,no,i,val;
    cin >> t;
    long a[]={3,5,15},b[3];
    for(int a0 = 0; a0 < t; a0++)
    {
        int n;
        cin >> n;
        for(i=0;i<3;i++)
        {
            if(n%a[i]==0) tmpn=n-1;
            else tmpn=n;
            no=tmpn/a[i];
            val=(no)*a[i];
            b[i]=(no*(a[i]+val))/2;
        }
        cout<<b[0]+b[1]-b[2]<<'\n';
    }
    return 0;
}
