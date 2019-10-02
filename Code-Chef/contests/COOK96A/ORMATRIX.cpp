#include <bits/stdc++.h>

using namespace std;


int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        int m, n, i, j ,k ,flag=1;
        char ch;
        cin >> m >> n;
        int a[m][n];
        vector<int> r(m,0),c(n,0);
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
            {
                cin >> ch;
                if (ch=='1')
                {
                    flag=0;
                    a[i][j] = 1;
                    r[i]++;
                    c[j]++;
                }   
                else a[i][j]=0;
            }
        }
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
            {
                if(flag) cout<<"-1 ";
                else if(a[i][j]==1) cout<<"0 ";
                else if(r[i]|c[j]) cout<<"1 ";
                else cout<<"2 ";
            } 
            cout<<'\n';
        } 
    }
    return 0;
}
