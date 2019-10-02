
def get_income_tax():
    amount_in_slab = [int(x) for x in input().split(' ')]
    percent_for_slab = [int(x) for x in input().split(' ')]
    prev_amount = 0 , prev_percent = 0
    slabs = []
    for i in range(len(amount_in_slab)):
        slabs.append((prev_amount,amount_in_slab[i],prev_percent))
        prev_amount = amount_in_slab[i]
        prev_percent = percent_for_slab[i]
