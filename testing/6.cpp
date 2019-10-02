#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
    int n,c,low,high,t,val,found=0,cprice=0;
    srand(time(NULL));
    cin>>n>>c;
    low=1,high=found=n;
    bool should_pay=false;
    while(low<=high&&cprice+c<=1000)
    {
        t=low+rand()%(high-low+1);
        cout<<"2\n";
        if(should_pay)
        {
            cout<<"2 "<<t<<endl;
            cprice+=c;
            should_pay=false;
        }
        else
        {
            cout<<"1 "<<t<<endl;
        }
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
    }
    //if(low==high) found=high;
    cout<<"2\n3 "<<found<<endl;
    return 0;
}