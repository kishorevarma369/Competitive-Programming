/*

      Question :-

          https://www.hackerrank.com/challenges/array-left-rotation/problem

      Idea:
          get the array and since d rotations just start printing from dth element
          to last element and then first to dth element

      ***************************************************************************
      --------------------written by KISHORE VARMA-------------------------------
      ***************************************************************************
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,d,t,i;
    cin >> n >> d;
    vector<int> a(n);
    for(i=0; i < n; i++)  cin>>a[i];
    d%=n;
    for (i = d; i <n-1; i++) cout << a[i]<<" ";
    cout<<a[i];
    if(d!=0)
    {
      cout<<" ";
      for (i = 0; i <d-1; i++) cout << a[i]<<" ";
      cout <<a[i]<<endl;
    }
    return 0;
}
