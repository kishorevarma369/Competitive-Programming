#include <stdio.h>

void countingSort(int n,int* arr, int *count)
{
    int i=0;
    for(i=0;i<n;i++) count[arr[i]]+=1;
}

int main()
{
    int n,i,j;
    scanf("%i", &n);
    int arr[n],count[100];
    for(i=0;i<n;i++) scanf("%d",&arr[i]);
    for(i=0;i<100;i++) count[i]=0;
    countingSort(n,arr,count);
    for(i=0;i<100;i++) for(j=0;j<count[i];j++) printf("%d ",i);
    return 0;
}
