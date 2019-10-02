mymod=int(1e9+7)
def fun():
    l=input()
    return int(l,2),len(l)

a,al=fun()
b,bl=fun()
ans=0
for i in range(0,314160):
    ans+=(a^b)%mymod
    b=b<<1
print(ans%mymod)
