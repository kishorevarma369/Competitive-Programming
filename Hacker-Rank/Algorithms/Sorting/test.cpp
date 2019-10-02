#include<bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    multiset<int> myset;
    for(int i=0;i<5;i++) myset.insert(i);
    for(int i=2;i<4;i++) myset.insert(i);
    for(auto &i:myset) cout<<i<<' ';
    auto it=myset.begin();
    advance(it,(myset.size()/2));
    advance(it,-2);
    cout<<'\n'<<*it<<'\n';
    return 0;
}
