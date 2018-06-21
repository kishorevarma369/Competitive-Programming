if __name__ == '__main__':
    n = int(input())
    if(n&1):
        print("Weird")
    else:
        if(n>20 or (n>=2 and n<=5)):
            print("Not Weird")
        else:
            print("Weird")
