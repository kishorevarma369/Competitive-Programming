

def fibonacciModified(t1, t2, n):
    n-=2
    t3=t2
    while n!=0:
        t3=t1+t2*t2
        t1,t2=t2,t3
        n-=1;
    return t3

if __name__ == "__main__":
    t1, t2, n = input().strip().split(' ')
    t1, t2, n = [int(t1), int(t2), int(n)]
    result = fibonacciModified(t1, t2, n)
    print(result)
