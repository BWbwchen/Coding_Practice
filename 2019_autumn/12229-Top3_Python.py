import sys

total = {}
fptr = sys.stdin
for line in fptr:
    ch, num = line.split(',')
    if ch in total:
        total[ch] += float(num)
    else :
        total[ch] = float(num)

for times in range(3) :
    max = -1000
    ans_ch = 0
    for element in total :
        if max < total[element] :
            max = total[element]
            ans_ch = element
    print(ans_ch, max, sep=',')
    del total[ans_ch]
