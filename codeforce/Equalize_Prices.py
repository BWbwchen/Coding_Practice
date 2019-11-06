#!/usr/bin/python
for _ in range(int(input())) :
    total, price  = map(int, input().split(' '))
    print("total and price", total, price, sep='+')
    li = list(map(int, input().split()))

    mi, mx = min(li), max(li)

    # check min+price >= max-price

    if mi+price >= mx-price :
        print(mi+price)
    else :
        print(-1)
