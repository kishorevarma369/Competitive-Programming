#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a,const void *b)
{
	return *((int *)a) > *((int *)b);
}
int time_taken_by_winner(int n, int weights[])
{
	int ans = 0;
	qsort(weights, n, sizeof(int), cmp);
	while (n > 1)
	{
		// for(int i=0;i<n;i++) printf("%d ",weights[i]);
		// putchar('\n');
		weights[0] += weights[1];
		ans += weights[0];
		weights[1] = 1000001;
		qsort(weights, n, sizeof(int), cmp);
		n--;
		// printf("ans = %d\n", ans);
	}
	return ans;
}

int main()
{
	int n = 6;
	int weights[6] = {3, 18, 22, 40, 5, 12};
	int expected = 226;
	printf("%d ",time_taken_by_winner(n, weights));
	return 0;
}