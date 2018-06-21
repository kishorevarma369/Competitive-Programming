#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    string s,mystack;
    cin>>s;
    int flag=0;
    for(auto i:s)
    {
        switch(i)
        {
            case '(':mystack.push_back(')');
                break;
            case '{':mystack.push_back('}');
                break;
            case '[':mystack.push_back(']');
                break;
        }
        if(i=='}'||i==']'||i==')')
        {
            if(mystack.size()!=0)
            {
                if(mystack.back()!=i) flag=1;
                mystack.pop_back();
            }
            else flag=1;
        }
        if(flag) break;
    }
    if(flag||mystack.size()!=0) cout<<"0";
    else cout<<"1";
    return 0;
}
