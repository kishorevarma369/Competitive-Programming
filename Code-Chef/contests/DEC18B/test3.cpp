// 4 9 10 11
#include<bits/stdc++.h>

using namespace std;
int n=8;


int main(int argc, char const *argv[])
{
    srand(time(NULL));

    // cin>>n;
    int a[n+5],b[2][n+5];
    for(int i=0;i<n;i++) a[i]=rand()%50;
    cout<<"original values:\n";
    for(int i=0;i<n;i++) cout<<a[i]<<' ';
    
    return 0;
}
