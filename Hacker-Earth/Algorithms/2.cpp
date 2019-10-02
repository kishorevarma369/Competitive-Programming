#include<bits/stdc++.h>

using namespace std;

double fun(double a,double b,double t)
{
    double ans=a/t;
    if(b>=2)
    {
        ans+=(b/t)*((b-1)/(t-1))*fun(a,b-2,t-2);
    }
    return ans;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        double a,b;
        cin>>a>>b;
        if(a==0||b==0) printf("1.000000\n");
        else
        {
            cout<<fun(a,b,t)<<'\n';
        }
    }
    return 0;
}