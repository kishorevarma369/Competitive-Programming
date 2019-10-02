def fun(denominations,n):
    l=[0]*n
    for denomination in denominations:
            for i in range(denomination,n,denomination):
                    p=i-denomination
                    if p==0:
                            l[i]=1
                    else:
                            l[i]=l[p]
    for i in range(1,n):
        if l[i] == 1:
            print(i)
