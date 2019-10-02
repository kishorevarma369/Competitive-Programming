#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;
#define MAX 500


int multiply(ll x, int res[], int res_size)
{
    int carry = 0;

    for (int i=0; i<res_size; i++)
    {
        int prod = res[i] * x + carry;
        res[i] = prod % 10;  
        carry  = prod/10;    
    }

    while (carry)
    {
        res[res_size] = carry%10;
        carry = carry/10;
        res_size++;
    }
    return res_size;
}

ll factorial(ll a,ll b,ll c)
{
    int res[MAX];
    ll temp=0;
    res[0] = 1;
    int res_size = 1;

    for (int x=b; x<=a; x++)
    {
        if(x==c || x%c==0)
        return 0;
        if(x>c)
        res_size = multiply(x%c, res, res_size);
    }

    cout << "Factorial of given number is \n";
    for (int i=res_size-1; i>=0; i--)
        temp=temp+res[i]*pow(10,i);
    return temp;
}


int main()
{
    long long int a,b,c,d,temp=0;
    cin>>a>>b>>c;
    d=factorial(a,b,c);
    cout<<d%c;
    return 0;
}