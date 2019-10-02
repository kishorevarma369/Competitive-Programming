n,k=[int(x) for x in input().split(' ')]
l=[int(x) for x in input().split(' ')]
ans=-1
if (k&1) == 0 :
    for i in range(0,min(n,k+1),2):
        ans=max(ans,l[i])
else :
    for i in range(1,min(n,k+1),2):
        ans=max(ans,l[i])
print(ans)