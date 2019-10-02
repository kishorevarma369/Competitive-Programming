t=int(input())
from collections import Counter
for i in range(t):
    s=input()
    p=Counter(s)
    print(len(p)-p.most_common(1)[0][1])