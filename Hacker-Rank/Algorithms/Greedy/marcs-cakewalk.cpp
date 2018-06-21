#include <bits/stdc++.h>

using namespace std;

long marcsCakewalk(vector <int> &calorie) {
    sort(calorie.begin(),calorie.end(),greater<long>());
    long i,j=1,pos=0,n=calorie.size(),co;
    co=calorie[0];
    for(i=1;i<n;i++)
    {
        co+=calorie[i]*(j<<=1);
    }
    return co;
}

int main() {
    int n;
    cin >> n;
    vector<int> calorie(n);
    for(int calorie_i = 0; calorie_i < n; calorie_i++){
       cin >> calorie[calorie_i];
    }
    long result = marcsCakewalk(calorie);
    cout << result << endl;
    return 0;
}
