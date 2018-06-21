b, n, L = 3, 4, 1000000000000
while n <= L:
    b, n = 3*b + 2*n - 2, 4*b + 3*n - 3

print(L)
print(b,n)
