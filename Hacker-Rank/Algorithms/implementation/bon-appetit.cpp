#include <bits/stdc++.h>

using namespace std;

void bonAppetit(int n, int k, int b, vector <int> ar) {
    int i=0,val=0;
    for(;i<n;i++)
    {
      if(i==k) continue;
      val+=ar[i];
    }
    val/=2;
    if(val==b) cout<<"Bon Appetit";
    else cout<<b-val;
}

int main() {
    int n;
    int k;
    cin >> n >> k;
    vector<int> ar(n);
    for(int ar_i = 0; ar_i < n; ar_i++){
       cin >> ar[ar_i];
    }
    int b;
    cin >> b;
    bonAppetit(n, k, b, ar);
    return 0;
}
