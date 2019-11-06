#!/usr/bin/python
import math
for _ in range(int(input())) :
    charge, turns, a, b = map(int, input().split(' '))
    # initial charge 
    # turns
    # a
    # b
    if charge - a * turns > 0 :
        print(turns)
    else :
        # diff = a - b
        # replace a with b will increase 'diff' charge
        # -(charge - a * turns) / diff = turns of b (bigger than)
        # but if -(charge - a * turns) == 0 so add 1 to let the ans be 1
        turn_b = math.ceil((-(charge - a * turns) + 1) / (a - b))
        if turn_b > turns :
            print(-1)
        else :
            print(turns - turn_b)
        #15 5 5 1
