#include<bits/stdc++.h>

using namespace std;

int mymax=0,mycount,n,p;
vector<tuple<int,int,int>> v;
void perform()
{
    int val1,val2,val3;
    for(int i=1;i<=p;i++)
    {
        val1=n%i;
        for(int j=1;j<=p;j++)
        {
            val2=val1%j;
            for(int k=1;k<=p;k++)
            {
                val3=(val2%k)%n;
                if(val3==mymax)
                {
                    v.push_back({i,j,k});
                }
                else if(val3>mymax)
                {
                    v.clear();
                    v.push_back({i,j,k});
                    mymax=val3;
                }
            }
        }
    }
    
    // int a,b,c;
    // for(auto &tup:v)
    // {
    //     tie(a,b,c)=tup;
    //     cout<<a<<' '<<b<<' '<<c<<'\n';
    // }
    // cout<<"\n----------------\n";
}

int main(int argc, char const *argv[])
{
    int t;
    // cin>>t;
    // while(t--)
    n=37;
    cout<<"n= "<<n<<'\n';
    for(p=1;p<200;p++)
    {
        // cin>>n>>p;
        mymax=0;
        v.clear();
        perform();
        // cout<<"\n----------------\n";
        cout<<"n= "<<n<<" p= "<<p;
        // cout<<" p= "<<p;
        cout<<" size= "<<v.size()<<" max element : "<<mymax<<'\n';
        // int a,b,c;
        // for(auto &tup:v)
        // {
        //     tie(a,b,c)=tup;
        //     cout<<a<<' '<<b<<' '<<c<<'\n';
        // }
        // cout<<"\n----------------\n";
        // system("pause");
        // cout<<"\n----------------\n";
    }
    
    //cout<<mymax<<' '<<mycount<<' ';
    return 0;
}
