# count sum
def mycount (string):
    sum = 0
    for ch in string :
        sum += int(ch)
    return sum

s = input()

while (mycount(s)%4 != 0) :
    s = str(int(s)+1)
print(int(s))
