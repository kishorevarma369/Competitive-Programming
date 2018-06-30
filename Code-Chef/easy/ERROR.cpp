#include<bits/stdc++.h>

using namespace std;


int main(int argc, char const *argv[])
{
    int t,i;
    cin>>t;
    int a[2][6]={{4,2,4,3,4,3},{1,1,3,3,5,1}};
    while(t--)
    {
        string s;
        cin>>s;
        int present_state=0;
        for(auto &i:s)
        {
            present_state=a[i-'0'][present_state];
            if(present_state==3) break;
        }
        if(present_state==3) cout<<"Good\n";
        else cout<<"Bad\n";
    }
    return 0;
}
