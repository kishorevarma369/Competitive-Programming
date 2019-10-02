def get_roman(n):
    values = [1,4,5,9,10,40,50,90,100,400,500,900,1000]
    roman_numerals = ["I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"] 
    roman_repr=''
    i = len(values)-1
    while n>0 :
        count = n//values[i]
        n = n%values[i]
        while count > 0 :
            count-=1
            roman_repr+=roman_numerals[i]
        i-=1
    return roman_repr

def find_ans(n):
    while  1<=n<=3999:
        s=get_roman(n)
        n=int(s,ord(max(s))-ord('A')+11)
    return n

n = int(input())
n = find_ans(n)
print(n)