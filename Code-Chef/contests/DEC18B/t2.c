#include<stdio.h> 
  
typedef struct
{
    int first,second;
} pair;

int cmp(const void *a,const void *b)
{
    pair c=*(pair *)a,d=*(pair *)b;
    if(c.first!=d.first) return c.first<d.first;
    return c.second<d.second;
}

int minSwaps(int arr[], int n) 
{ 
    pair arrPos[n]; 
    for (int i = 0; i < n; i++) 
    { 
        arrPos[i].first = arr[i]; 
        arrPos[i].second = i; 
    } 
    qsort(arrPos, n,sizeof(pair),cmp); 
    int vis[n]; 
    for(int i=0;i<n;i++) vis[i]=0;
    int ans = 0; 
    for (int i = 0; i < n; i++) 
    { 
        if (vis[i] || arrPos[i].second == i) 
            continue; 
        int cycle_size = 0; 
        int j = i; 
        while (!vis[j]) 
        { 
            vis[j] = 1; 
            j = arrPos[j].second; 
            cycle_size++; 
        }  
        if (cycle_size > 0) 
        { 
            ans += (cycle_size - 1); 
        } 
    } 
    return ans; 
} 

int main() 
{ 
    int n;
    scanf("%d",&n);
    int a[n],k;
    for(int i=0;i<n;i++) scanf("%d",a+i);
    int t=minSwaps(a,n);
    scanf("%d",k);
    if(t<=k) printf("Yes\n");
    else printf("No\n");
    return 0; 
} 