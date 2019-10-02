#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t,n,start,end,counter=0,val,y,x,ans;
    string days[]={"saturday", "sunday", "monday", "tuesday", "wednesday", "thursday" ,"friday"},sday,eday;
    map<string,int> mday;
    for(int i=0;i<7;i++) mday[days[i]]=i;
    cin>>t;
    while(t--)
    {
        counter=0;
        cin>>sday>>eday>>start>>end;
        val=(mday[eday]-mday[sday]);
        val=(val+7)%7;
        val++;
        for(x=0;;x++)
        {
            y=7*x+val;
            if(y>=start&&y<=end) ans=y,counter++;
            else if(y>end) break;
        }
        if(counter==1) cout<<ans<<'\n';
        else if(counter==0) cout<<"impossible\n";
        else cout<<"many\n";
    }
}