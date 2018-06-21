#include <stdio.h>

void countingSort(int n,int* arr, int *count)
{
    int i=0;
    for(i=0;i<n;i++) count[arr[i]]+=1;
}

int main()
{
    int n,i;
    scanf("%i", &n);
    int arr[n],count[100];
    for(i=0;i<n;i++) scanf("%d",&arr[i]);
    for(i=0;i<100;i++) count[i]=0;
    countingSort(n,arr,count);
    for(i=0;i<100;i++) printf("%d ",count[i]);
    return 0;
}
