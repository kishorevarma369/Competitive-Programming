#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,k;
    cin>>n;
    while(n)
    {
        n++;
        int m[10]={0};
        auto t=n;
        while(t)
        {
            k=t%10;
            if(m[k]==0) m[k]=1;
            else break;
            t/=10;
        }
        if(!t){
            cout<<n<<'\n';
            break;
        } 
        
    }
    return 0;
}