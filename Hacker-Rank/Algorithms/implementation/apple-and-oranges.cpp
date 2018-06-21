#include <bits/stdc++.h>

using namespace std;

void countApplesAndOranges(int s, int t, int a, int b, vector <int> apples, vector <int> oranges) {
    int i,count=0,count1=0;
    for(i=0;i<apples.size();i++)
    {
      if(s<=apples[i]+a&&t>=apples[i]+a)
      {
        count++;
      }
    }
    for(i=0;i<oranges.size();i++)
    {
      if(s<=oranges[i]+b&&t>=oranges[i]+b)
      {
        count1++;
      }
    }
    cout<<count<<' '<<count1<<'\n';
}

int main() {
    int s;
    int t;
    cin >> s >> t;
    int a;
    int b;
    cin >> a >> b;
    int m;
    int n;
    cin >> m >> n;
    vector<int> apple(m);
    for(int apple_i = 0; apple_i < m; apple_i++){
       cin >> apple[apple_i];
    }
    vector<int> orange(n);
    for(int orange_i = 0; orange_i < n; orange_i++){
       cin >> orange[orange_i];
    }
    countApplesAndOranges(s, t, a, b, apple, orange);
    return 0;
}
