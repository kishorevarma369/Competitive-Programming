#include <bits/stdc++.h>

using namespace std;

int main() {
    int t,k;
    cin >> t;
    while(t--)
    {
        cin>>k;
        if(k%7==0||k%7==1) cout<<"Second\n";
        else cout<<"First\n";
    }
    return 0;
}
