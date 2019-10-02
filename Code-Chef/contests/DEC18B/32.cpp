#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
    int n,c,low,high,t,val,found=0,i=1,cou=0;
    srand(time(NULL));
    cin>>n>>c;
    low=1,high=found=n;
    bool should_pay=false;
    cou=1000/c;
    cou--;
    while(low<=high)
    {
        if(i&1) t=low+int(ceil(0.375*(high-low+1)));
        else t=low+int(ceil(0.25*(high-low+1)));
        if(should_pay)
        {
            cout<<"2"<<endl;
            should_pay=false;
            cou--;
            if(cou==0) goto another;
        }
        cout<<"1 "<<t<<endl;
        cin>>val;
        if(val)
        {
            should_pay=true;
            high=t-1;
            found=t;
        }
        else
        {
            low=t+1;
        }
        i++;
    }
    //if(low==high) found=high;
    cout<<"3 "<<found<<endl;
    return 0;
    another:
    for(int j=low;j<=high;j++)
    {
        cout<<"1 "<<j<<endl;
        cin>>val;
        if(val)
        {
            cout<<"2"<<endl;
            found=j;
            break;
        }
    }
    cout<<"3 "<<found<<endl;
    return 0;
}