def fun():
  n=int(input())
  total=(n*(n+1)*(2*n+1))/6
  sum=(n+1)*(n+1)
  sum=(sum*(sum-1))/12
  print(int(sum//total))
n=int(input())
while n!=0:
    n-=1
    fun()
