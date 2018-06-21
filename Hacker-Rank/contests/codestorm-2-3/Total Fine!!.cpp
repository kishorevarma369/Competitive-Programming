/*
https://www.hackerrank.com/contests/codestorm-2-3/challenges/total-fine/problem
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int exp[3],ret[3];
    cin>>ret[0]>>ret[1]>>ret[2];
    cin>>exp[0]>>exp[1]>>exp[2];

    if(ret[2]==exp[2])
    {
        if(ret[1]==exp[1])
        {
            if(ret[0]<=exp[0]) cout<<"0";
            else cout<<15*(ret[0]-exp[0]);
        }
        else if(ret[1]<exp[1]) cout<<"0";
        else cout<<(ret[1]-exp[1])*500;
    }
    else if(ret[2]<exp[2]) cout<<"0";
    else cout<<"10000\n";
    return 0;
}
