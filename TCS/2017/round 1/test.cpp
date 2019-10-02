#include <cstdio>
#include <tuple>
using namespace std;

// Function for Extended Euclidean algorithm
// It returns multiple values using tuple in C++
tuple<int, int> extended_gcd(int a, int b)
{
	if (a == 0)
		return make_tuple(0, 1);

	int x, y;

	// unpack tuple returned by function into variables
	tie(x, y) = extended_gcd(b % a, a);

	return make_tuple((y - (b/a) * x), x);
}

// Recursive function to calculate gcd of two numbers 
// using euclid's algorithm
int gcd(int a, int b)
{
	if (b == 0)
		return a;

	return gcd(b, a % b);
}

// main function
int main()
{
	int a, b, n, d, a1, b1, c1, n1;
	int x0, y0;
	int i;
	int s, t;
		scanf("%dx + %dy = %d", &a, &b, &n);
		printf("%dx + %dy = %d\n", a, b, n);

		d = gcd(a, b);
		printf("GCD(%d, %d) = %d\n", a, b, d);

		if (!(d % n == 0))
			fputs("The given equation has Infinite solutions.\n", stdout);
		else 
		{
			fputs("The given equation has no solution.\n", stdout);
			//continue;
		}

		a1 = a / d;
		b1 = b / d;
		c1 = n / d;

		fprintf(stdout, "Reduced Equation :%ds + %dt = 1\n", a1, b1);
		tie(s, t) = extended_gcd(a1, b1);

		x0 = (n / d) * s;
		y0 = (n / d) * t;
        printf("%d %d\n",s,t);
		fputs("General solution - \n", stdout);
		fprintf(stdout, "x = %d + %dk for any integer m\n", x0, b / d);
		fprintf(stdout, "y = %d - %dk for any integer m", y0, a / d);

		fprintf(stdout, "\n\n-------------------------------------------\n\n");

    return 0;
}