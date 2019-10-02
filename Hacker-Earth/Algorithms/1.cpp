#include<bits/stdc++.h>

using namespace std;

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
            double ans=a/(a+b),prev=1,nans=0;
            while(b>=2&&ans-nans>1e-7)
            {
                prev*=(b*(b-1)/((a+b-1)*(a+b)));
                b-=2;
                nans=ans;
                ans+=prev*(a/(a+b));
            }
            printf("%.6lf\n",ans);
        }
    }
    return 0;
}