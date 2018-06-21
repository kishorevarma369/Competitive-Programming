#include <bits/stdc++.h>

using namespace std;

int surfaceArea(vector < vector<int> > &A)
{
    int i,j,m=A.size(),n=A[0].size();
    int sa=m*n*2,rco=0,rinc=0,rowflag=0,rmax=0,rdec;
    for(i=0;i<m;i++)
    {
        rmax=A[i][0];
        rowflag=0;
        rinc=rco=rdec=0;
        for(j=1;j<n;j++)
        {
            if(A[i][j-1]<A[i][j])
            {
                rinc+=A[i][j]-A[i][j-1];
                if(rowflag)
                {
                    if(rdec<=rinc)
                    {
                        sa+=2*(rdec);
                        rowflag=0;
                        rinc=rdec=0;
                    }
                    else
                    {
                        sa+=2*rinc;
                        rdec-=rinc;
                        rinc=0;
                    }
                }
                if(rmax<A[i][j])
                {
                    rmax=A[i][j];
                    rinc=0;
                }
            }
            else if(A[i][j-1]>A[i][j])
            {
                rowflag=1;
                rdec+=A[i][j-1]-A[i][j];
            }
        }
        sa+=2*rmax;
    }
    for(i=0;i<n;i++)
    {
        rmax=A[0][i];
        rowflag=0;
        rinc=rco=rdec=0;
        for(j=1;j<m;j++)
        {
            if(A[j-1][i]<A[j][i])
            {
                rinc+=A[j][i]-A[j-1][i];
                if(rowflag)
                {
                    if(rdec<=rinc)
                    {
                        sa+=2*(rdec);
                        rowflag=0;
                        rinc=rdec=0;
                    }
                    else
                    {
                        sa+=2*rinc;
                        rdec-=rinc;
                        rinc=0;
                    }
                }
                if(rmax<A[j][i])
                {
                    rmax=A[j][i];
                    rinc=0;
                }
            }
            else if(A[j-1][i]>A[j][i])
            {
                rowflag=1;
                rdec+=A[j-1][i]-A[j][i];
            }
        }
        sa+=2*rmax;
    }
    return sa;
}

int main() {
    int H;
    int W;
    cin >> H >> W;
    vector< vector<int> > A(H,vector<int>(W));
    for(int A_i = 0;A_i < H;A_i++){
       for(int A_j = 0;A_j < W;A_j++){
          cin >> A[A_i][A_j];
       }
    }
    int result = surfaceArea(A);
    cout << result << endl;
    return 0;
}
