#include <bits/stdc++.h>

using namespace std;

int fairRations(vector <int> B)
{
    int i,size=B.size(),count=0;
    for(i=0;i<size;i++) if(B[i]&1) count++;
    if(count&1)

    return -1;
}

int main() {
    int N;
    cin >> N;
    vector<int> B(N);
    for(int B_i = 0; B_i < N; B_i++){
       cin >> B[B_i];
    }
    int result = fairRations(B);
    cout << result << endl;
    return 0;
}
