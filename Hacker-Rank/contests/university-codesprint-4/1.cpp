#include <bits/stdc++.h>

using namespace std;

struct myda
{
    int len;
    int freq;
};
typedef struct myda box;
struct cyl
{
    int rad;
    int cap;
};
typedef struct cyl cylinder;

bool compareBySize(const box &a, const box &b)
{
    return a.len > b.len;
}
bool compareByRad(const cyl &a, const cyl &b)
{
    return a.rad > b.rad;
}

int maximumPackages(vector<int> &S, vector<int> &K, vector<int> &R, vector<int> &C) {
    // Return the maximum number of packages that can be put in the containers.
    vector<box> b(S.size());
    vector<cylinder> c(R.size());
    int bsize=S.size(),csize=R.size(),i,j,count=0,flag;
    for(i=0;i<bsize;i++)
    {
        b[i].len=S[i];
        b[i].freq=K[i];
    }
    for(i=0;i<csize;i++)
    {
        c[i].rad=R[i];
        c[i].cap=C[i];
    }
    sort(b.begin(),b.end(),compareBySize);
    sort(c.begin(),c.end(),compareByRad);
    for(i=0;i<bsize;i++)
    {
        flag=1;
        for(j=0;j<csize;j++)
        {
            if(c[j].cap)
            {
                flag=0;
                if(2*c[j].rad*c[j].rad>b[i].len*b[i].len)
                {
                    if(c[j].cap>=b[i].freq)
                    {
                        count+=b[i].freq;
                        c[j].cap=c[j].cap-b[i].freq;
                        break;
                    }
                    else
                    {
                        count+=c[j].cap;
                        b[i].freq=b[i].freq-c[j].cap;
                        c[j].cap=0;
                    }
                }
            }

        }
        if(flag) break;
    }
    return count;
}


int main()
{

    int m,n,i;
    cin>>m>>n;
    vector<int> s(m),k(m),r(n),c(n);
    for(i=0;i<m;i++) cin>>s[i];
    for(i=0;i<m;i++) cin>>k[i];
    for(i=0;i<n;i++) cin>>r[i];
    for(i=0;i<n;i++) cin>>c[i];
    cout<<maximumPackages(s,k,r,c);

    return 0;
}
