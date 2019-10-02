t=int(input())
def sub(a,b):
    l=len(a)
    res=''
    borrow=0
    for i in range(l-1,-1,-1):
        c,d=int(a[i]),int(b[i])
        c=c-borrow
        borrow=0
        if c-d>=0:
            res=str(c-d)+res
        else:
            borrow=1
            res=str(2+(c-d))+res
    return res

def add(a,b):
    l=len(a)
    res=''
    carry=0
    for i in range(l-1,-1,-1):
        c,d=int(a[i]),int(b[i])
        c=c+carry
        carry=0
        if c+d>1:
            res=str((c+d)%2)+res
            carry=(c+d)//2
        else:
            res=str(c+d)+res
    return res

while(t):
    n=int(input())
    a=input()
    b=input()
    a=a+'0'
    b=b+'0'
    x=a.count('1')
    y=b.count('1')
    result=sub(b,a)
    if(y-x>0):
        z=bin(y-x)[2:]
        z='0'*(len(a)-len(z))+z
        result=sub(result,z)
    else:
        z=bin(x-y)[2:]
        z='0'*(len(a)-len(z))+z
        result=add(result,z)
    print(result[result.find('1'):])
    t-=1