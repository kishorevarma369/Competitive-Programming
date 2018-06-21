#include <bits/stdc++.h>

using namespace std;

int gemstones(vector <string> arr)
{
      int count=0;
      map<char,int> gemmap;
      for(int i=0;i<arr.size();i++)
      {
        map<char,int> tmap;
        for(int j=0;j<arr[i].size();j++) tmap[arr[i][j]]++;
        for(auto j:tmap)
        {
          gemmap[j.first]++;
        }
      }
      for(auto j:gemmap)
      {
        if(j.second==arr.size()) count++;
      }
      return count;
}

int main() {
    int n;
    cin >> n;
    vector<string> arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> arr[arr_i];
    }
    int result = gemstones(arr);
    cout << result << endl;
    return 0;
}
