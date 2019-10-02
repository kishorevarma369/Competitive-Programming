#include<bits/stdc++.h>

using namespace std;

int main()
{
    // 1.23 8.90 -5.67
    float k,a=0,b=0,c=0,d=0,oi,oj,ok,ol,mymax=0,t,l;
    // oi=1.23,oj=8.9,ok=-5.67;
    int cou=0;
    float mi,mj,mk,ml;
    oi=5,oj=6,ok=7,ol=8;
    for(float i=-oi;i<=30;i+=0.05)
    {
        for(float j=-oj;j<=30;j+=0.05)
        {
            for(float k=-ok;k<=30;k+=0.05)
            {
                l=-(1*i+2*j+3*k)/4;
                if(l>=ol)
                {
                    // a=i,b=j,c=l;
                    a=i+oi,b=j+oj,c=k+ok,d=l+ol;
                    t=sqrt(a)+sqrt(b)+sqrt(c)+sqrt(d);
                    if(t>mymax)
                    {
                        mymax=t;
                        mi=i,mj=j,mk=k,ml=l;
                        printf("%.2f %.2f %.2f %.2f\t %.2f %.2f %.2f %.2f\n",i,j,k,l,i,2*j,3*k,4*l);
                        cou++;
                        if(cou==5) return 0;
                    }
                }
            }
            // k=-(i+j);
            // if(k>=ok)
            // {
            //     // a=i,b=j,c=k;
            //     a=i+oi,b=j+oj,c=k+ok;
            //     t=sqrt(a)+sqrt(b)+sqrt(c);
            //     if(t>mymax)
            //     {
            //         mymax=t;
            //         printf("%f %f %f\n",i,j,k);
            //     }
            // }
        }
    }
    cout<<mymax<<'\n';
    printf("%.3f %.3f %.3f %.3f\n",mi,mj,mk,ml);
    return 0;
}