#include <bits/stdc++.h>

using namespace std;

int gridlandMetro(int m, int n, int k, vector < vector<int> >& track)
{

}

int main() {
    ios::base sync_with_stdio(false);
    int n;
    int m;
    int k;
    cin >> n >> m >> k;
    vector< vector<int> > track(k,vector<int>(3));
    for(int track_i = 0;track_i < k;track_i++){
       for(int track_j = 0;track_j < 3;track_j++){
          cin >> track[track_i][track_j];
       }
    }
    int result = gridlandMetro(n, m, k, track);
    cout << result << endl;
    return 0;
}
