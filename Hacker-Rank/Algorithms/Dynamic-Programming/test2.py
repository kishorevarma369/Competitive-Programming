from collections import defaultdict

M=1000000007
a = str(input())
b = str(input())

# need to change n into 314159
n=314159
# pre-compute powers of 2 up to n=314159
pof2=[1]
for i in range(n+1):
    pof2.append((pof2[-1]*2)%M)

# use a default list to count the number of 1's in b in the right k digits
len_a=len(a)
len_b=len(b)
#print(len_a,len_b)
cnt_b=defaultdict(int)
cnt_b[0]=int(b[-1])
for i in range(1,len_b):
    cnt_b[i]=cnt_b[i-1]+int(b[-i-1])
# extend to the length of a
for i in range(len_b,len_a):
    cnt_b[i]=cnt_b[len_b-1]

# using pof2 to compute num_a%M,num_b%M
num_a=0
num_b=0
for i in range(len_a):
    if int(a[-1-i])!=0:
        num_a+=pof2[i]
for i in range(len_b):
    if int(b[-1-i])!=0:
        num_b+=pof2[i]
#print(num_a,num_b)

#compute the offset
offset=0
for i in range(len_a):
    if int(a[-i-1])!=0:
        offset+=pof2[i+1]*cnt_b[i]
#print(offset)

# n=314159, which is very large
answer=(num_b*(pof2[n+1]-1)+num_a*(n+1)-offset)%M
print(answer)
