mymod=int(1e9+7)
def fun():
    l=input()
    return int(l,2),len(l)

a,al=fun()
b,bl=fun()
c=b
ans=0
for i in range(al):
    ans=ans+a^b
    b<<=1
ans=ans%mymod
b%=mymod
for i in range(al,314160):
    ans=(ans+b)%mymod
    b=(b<<1)%mymod
a%=mymod
ans=(ans+(314160-al)*a)%mymod
print(ans)

'''
11
 1

11
10

011
100

0011
1000

00011
10000

000011
100000

'''

