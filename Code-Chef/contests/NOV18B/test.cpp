#include<iostream>
#include<vector>
#include<utility>
using namespace std;
#define MAX_LINE_INPUT 1000000
#define lint long long int
#define ulint unsigned long long int
#define uint unsigned int

#define NUM 1000000007
/*==================*/
int scan_int(){
	int x = 0;
	bool negative = false;
	register int z = getchar();
	/* for ill-formatted data */
	while(!(z=='-' || (z>47&&z<58))) z = getchar();
	if(z=='-') {
		negative = true;
		z = getchar();
	}
	for(;z>47 && z<58;z=getchar())
		x = x*10 + z - 48;
	if(negative) x*=-1;
	return x;
}
/*===============*/
uint scan_uint(){
	uint x = 0;
	bool negative = false;
	register int z = getchar();
	/* for ill-formatted data */
	while(!(z>47&&z<58)) z = getchar();
	for(;z>47 && z<58;z=getchar())
		x = x*10 + z - 48;
	return x;
}
/*===============*/
string scan_line(){
	char* arr = new char[MAX_LINE_INPUT];
	int i = 0;
	register int z;
	z = getchar();
	while(z!='\n' && z!=EOF){
		arr[i++]=z;
		z = getchar();
	}
	arr[i]='\0';
	string s = string(arr);
	delete(arr);
	return s;
}
/*===============*/
const int N = 1000; 
// array to store inverse of 1 to N 
lint factorialNumInverse[N + 1]; 
  
// array to precompute inverse of 1! to N! 
lint naturalNumInverse[N + 1]; 
  
// array to store factorial of first N numbers 
lint fact[N + 1]; 
  
// Function to precompute inverse of numbers 
void InverseofNumber(lint p) 
{ 
    naturalNumInverse[0] = naturalNumInverse[1] = 1; 
    for (int i = 2; i <= N; i++) 
        naturalNumInverse[i] = naturalNumInverse[p % i] * (p - p / i) % p; 
} 
// Function to precompute inverse of factorials 
void InverseofFactorial(lint p) 
{ 
    factorialNumInverse[0] = factorialNumInverse[1] = 1; 
  
    // precompute inverse of natural numbers 
    for (int i = 2; i <= N; i++) 
        factorialNumInverse[i] = (naturalNumInverse[i] * factorialNumInverse[i - 1]) % p; 
} 
  
// Function to calculate factorial of 1 to N 
void factorial(lint p) 
{ 
    fact[0] = 1; 
  
    // precompute factorials 
    for (int i = 1; i <= N; i++) { 
        fact[i] = (fact[i - 1] * i) % p; 
    } 
} 
  
// Function to return nCr % p in O(1) time 
lint Binomial(lint N, lint R, lint p) 
{ 
    // n C r = n!*inverse(r!)*inverse((n-r)!) 
    lint ans = ((fact[N] * factorialNumInverse[R]) 
              % p * factorialNumInverse[N - R]) 
             % p; 
    return ans; 
} 
/*===============*/
int two_exp_mod(int z, int p)
{
	int r = 1;
	for (int i = 0; i < z; ++i)
	{
		r = r<<1;
		r%=p;
	}
	return r;
}
int main(){
	InverseofNumber(NUM);
	InverseofFactorial(NUM);
	factorial(NUM);
	int t = scan_int();
	while(t--){
		int n = scan_int();
		int a[n];
		for (int i = 0; i < n; ++i)
			a[i] = scan_int();
		/*=construct x,l,g=*/
		int x[2*n+1],l[2*n+1],g[2*n+1];
		for (int i = 1; i <= 2*n; ++i)
			x[i] = 0;
		for (int i = 0; i < n; ++i)
			x[a[i]]++;
		int sum_z = 0;
		for (int i = 1; i <= 2*n; ++i)
		{
			l[i] = sum_z;
			sum_z+=x[i];
		}
		sum_z = 0;
		for (int i = 2*n; i >= 0; --i)
		{
			g[i] = sum_z;
			sum_z+=x[i];
		}
		/*==============*/
		int result = two_exp_mod(n-1,NUM);

		for (int i = 1; i <= 2*n; ++i)
		{
			if(x[i]>1){
				int p = l[i];
				int q = g[i];
				int r = x[i];
				lint sum = 0;
				for (int j = 2; j <= r; ++j)
				{
					lint temp = 0;
					for (int k = 1; k <= j-1; ++k)
					{
						int z = p+j-2*k;
						if(z>-1 && z<=p+q) temp+= Binomial(p+q,z,NUM);
					}
					temp%=NUM;
					temp*= Binomial(r,j,NUM);
					sum+=temp;
					sum%=NUM;
				}
				result+=sum;
				result%=NUM;
			}
		}
		cout << result << '\n';
	}

	
}