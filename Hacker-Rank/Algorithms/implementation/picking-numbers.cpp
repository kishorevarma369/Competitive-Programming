#include <bits/stdc++.h>

using namespace std;

int pickingNumbers(vector <int> a)
{
    int  i,size=a.size(),b[100]={0},count=0,val;
    for(i=0;i<size;i++) b[a[i]]++;
    for(i=1;i<100;i++)
    {
      val=b[i]+b[i-1];
      if(val>count) count=val;
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int a_i = 0; a_i < n; a_i++){
       cin >> a[a_i];
    }
    int result = pickingNumbers(a);
    cout << result << endl;
    return 0;
}
