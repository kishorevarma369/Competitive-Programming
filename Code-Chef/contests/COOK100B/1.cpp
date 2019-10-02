#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--)
    {
        int a[2][105]={0},p[2],q[2],val;
        for(int j=0;j<2;j++)
        {
            cin>>p[j];
            for(int i=0;i<p[j];i++) cin>>val,a[j][val]=1;
        }
        int c=0;
        for(int j=0;j<2;j++)
        {
            cin>>q[j];
            for(int i=0;i<q[j];i++) {
                cin>>val;
                //very greedy skipped all the input and used goto
                if(a[j][val]==0) c=1;
            }
        }
        if(c) goto ans;
        cout<<"yes\n";
        continue;
        ans:
        cout<<"no\n";

    }
    return 0;
}
