#include <bits/stdc++.h>

using namespace std;
map<long,int> mymap;
int minimumLoss(vector <long> &a)
{
  sort(a.begin(),a.end());
  long n=a.size(),val;
  int mi=INT_MAX,i;
  for(i=1;i<n;i++)
  {
    val=a[i]-a[i-1];
    if(mi>val&&mymap[a[i]]<mymap[a[i-1]]) mi=val;
  }
  return mi;
}

int main() {
    int n;
    cin >> n;
    vector<long> price(n);
    for(int price_i = 0; price_i < n; price_i++){
       cin >> price[price_i];
       mymap[price[price_i]]=price_i;
    }
    int result = minimumLoss(price);
    cout << result << endl;
    return 0;
}
