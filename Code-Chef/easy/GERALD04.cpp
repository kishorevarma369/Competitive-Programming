#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t,t1,t2,h,m,dist;
    float ans;
    cin>>t;
    while(t--)
    {
        scanf("%d:%d",&h,&m);
        t1=h*60+m;
        scanf("%d:%d",&h,&m);
        t2=h*60+m;
        scanf("%d",&dist);
        printf("%.1f ",(float)(t1-t2+dist));
        if(dist<=t1-t2-dist)
        {
            ans=t1-t2;
            //meet at bus stop
        }
        else
        {
            t2+=dist;
            if(t1<=t2)
            {
                //she crossed bus stop and on the way to home
                ans=dist-(t2-t1);
                ans/=2;
                ans+=dist;
            }
            else
            {
                //she didnt reach bus stop yet but chef and gf will meet on their way
                ans=dist-(t1-t2);
                ans/=2;
                ans+=dist+(t1-t2);
            }
            
        }        
        printf("%.1f\n",ans);
    }
    return 0;
}