import math

def get_slabs():
    slabs_list=[0]+[int(i) for i in input().split()]+[math.inf]
    percent=[0]+[int(i) for i in input().split()]
    slabs=[]
    for i in range(len(slabs_list)-1):
        val=(slabs_list[i+1]-slabs_list[i])*percent[i]/100
        slabs.append((slabs_list[i],slabs_list[i+1],percent[i],val))
    return slabs
slabs=get_slabs()
rebate=int(input())
tax_paid=[int(i) for i in input().split()]
final_ans=0
for employee_paid in tax_paid:
    ans=rebate
    for slab in slabs:
        if employee_paid - slab[3] == 0  :
            ans+=slab[0]+employee_paid*100/slab[2]
            break
        elif slab[3] == math.inf :
            ans+=slab[0]+employee_paid*100/slab[2]
            break
        elif employee_paid - slab[3] > 0 :
            employee_paid-=slab[3]
        else:
            ans+=slab[0]+employee_paid*100/slab[2]
            break
    final_ans+=ans
print(int(final_ans))