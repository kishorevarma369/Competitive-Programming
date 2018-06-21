#include <bits/stdc++.h>

using namespace std;

vector <int> permutationEquation(vector <int> p) {
    vector<int> p1(p.size(),0);
    for(int i=1;i<p.size();i++)
    {
      p1[p[p[i]]]=i;
    }
    return p1;
}

int main() {
    int n;
    cin >> n;
    vector<int> p(n+1);
    p[0]=0;
    for(int p_i = 1; p_i <= n; p_i++){
       cin >> p[p_i];
    }
    vector <int> result = permutationEquation(p);
    for (ssize_t i = 1; i < result.size(); i++) {
        cout << result[i] << (i != result.size() - 1 ? "\n" : "");
    }
    cout << endl;


    return 0;
}
