#include<bits/stdc++.h>

using namespace std;

#define uplim 100005

int n,a[uplim],ps,pc,temp[2][8],pos=0;

void get_input4()
{
    // cout<<"1 "<<1+ps<<' '<<2+ps<<' '<<3+ps<<endl;
    cin>>temp[0][0];
    // cout<<"1 "<<2+ps<<' '<<3+ps<<' '<<4+ps<<endl;
    cin>>temp[0][1];
    // cout<<"1 "<<1+ps<<' '<<3+ps<<' '<<4+ps<<endl;
    cin>>temp[0][2];
    // cout<<"1 "<<1+ps<<' '<<2+ps<<' '<<4+ps<<endl;
    cin>>temp[0][3];
    temp[0][4]=temp[0][0];
    for(int i=0;i<4;i++) temp[1][i]=temp[0][i]^temp[0][i+1];
    temp[1][4]=temp[1][0];
    temp[1][5]=temp[1][1];
    for(int i=0;i<4;i++){ cout<<(a[pos++]=(temp[0][i]^temp[1][i+2]));
    }
}

void get_input5()
{
    // cout<<"1 "<<1+ps<<' '<<2+ps<<' '<<3+ps<<endl;
    cin>>temp[0][0];
    // cout<<"1 "<<2+ps<<' '<<3+ps<<' '<<4+ps<<endl;
    cin>>temp[0][1];
    // cout<<"1 "<<3+ps<<' '<<4+ps<<' '<<5+ps<<endl;
    cin>>temp[0][2];
    // cout<<"1 "<<1+ps<<' '<<4+ps<<' '<<5+ps<<endl;
    cin>>temp[0][3];
    // cout<<"1 "<<1+ps<<' '<<2+ps<<' '<<5+ps<<endl;
    cin>>temp[0][4];
    temp[0][5]=temp[0][0];
    for(int i=0;i<5;i++) temp[1][i]=temp[0][i]^temp[0][i+1];
    temp[1][5]=temp[1][0];
    //temp[1][6]=temp[1][1];
    cout<<(a[pos++]=temp[0][4]^temp[1][1]);
    for(int i=0;i<4;i++) cout<<(a[pos++]=(temp[0][i]^temp[1][i+2]));
}

void process()
{
    pc=(n-(n%4)*5)/4;
    for(int i=0;i<pc;i++,ps+=4) get_input4();
    pc=n%4;
    for(int i=0;i<pc;i++,ps+=5) get_input5();
}

void print()
{
    cout<<"2 ";
    for(int i=0;i<n;i++) cout<<a[i]<<' ';
    cout<<endl;    
}

int main()
{
    int t;
    int val;
    cin>>t;
    while(t--)
    {
        cin>>n;
        process();
        print();
        cin>>val;
        if(val==-1) break;
    }
    return 0;
}