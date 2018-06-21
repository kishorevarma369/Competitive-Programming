#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,count=0;
    int k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> arr[arr_i];
    }
    sort(arr.begin(),arr.end());
    auto i=arr.begin();
    for(;i!=arr.end();i++)
    {
      if(binary_search(i+1,arr.end(),*i+k)) count++;
    }
    cout << count << endl;
    return 0;
}
