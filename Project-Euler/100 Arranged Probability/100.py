from decimal import *
import math
a=1000000000001
#getcontext().prec =
while 1:
    b=1+2*a*(a-1)
    c=Decimal(b).sqrt()
    d=math.floor(c)
    e=(1+d)//2
    if c==d:
        print(e,' ',a)
        break
    print(e,' ',a)
    a=a+1
