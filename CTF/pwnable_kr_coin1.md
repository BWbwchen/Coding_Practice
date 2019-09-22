# coin 1
```
	---------------------------------------------------
	-              Shall we play a game?              -
	---------------------------------------------------
	
	You have given some gold coins in your hand
	however, there is one counterfeit coin among them
	counterfeit coin looks exactly same as real coin
	however, its weight is different from real one
	real coin weighs 10, counterfeit coin weighes 9
	help me to find the counterfeit coin with a scale
	if you find 100 counterfeit coins, you will get reward :)
	FYI, you have 60 seconds.
	
	- How to play - 
	1. you get a number of coins (N) and number of chances (C)
	2. then you specify a set of index numbers of coins to be weighed
	3. you get the weight information
	4. 2~3 repeats C time, then you give the answer
	
	- Example -
	[Server] N=4 C=2 	# find counterfeit among 4 coins with 2 trial
	[Client] 0 1 		# weigh first and second coin
	[Server] 20			# scale result : 20
	[Client] 3			# weigh fourth coin
	[Server] 10			# scale result : 10
	[Client] 2 			# counterfeit coin is third!
	[Server] Correct!

	- Ready? starting in 3 sec... -

```

note that each game only contain 1 counterfeit coin!
I think that for each case have many counterfeit so it cause me waste lots of time QQ

so just use binary search search '9' in all '10'

If you use 'nc', it is so slow !
so just login other problem's server, and go to /tmp , and use pwntool for solve this problem !
```
> ssh fd@pwnable.kr -p2222
> cd /tmp
> vim mypysolution.py
> python mypysolution.py
```


## Solution
``` python
#!/usr/bin/env python3
from pwn import *


# make connect
conn = remote('pwnable.kr', 9007)
# ignore the introduction
conn.recv(10024)


for _ in range(100) :
    # list
    problem = conn.recv(1024).decode('UTF-8').strip().split()
    print(problem)
    # print(problem)
    n = (int)(problem[0].split('=')[1])
    c = (int)(problem[1].split('=')[1])

    # 0 ~ c-1
    left = 0
    right = n-1
    middle = (right+left)//2
    for times in range(c) :
        # generate the index set
        # input
        li = []
        for index in range(left, middle+1) :
            li.append(str(index))
        conn.sendline(' '.join(li))

        # output 
        _sum = conn.recv(1024).decode('UTF-8').strip()
        print(_sum)
        if (int(_sum) % 10 != 0 ):
            right = middle
        else :
            left = middle+1
        middle = (right+left)//2

    conn.sendline(str(left))
    print(conn.recv(1024).decode('UTF-8'))
        
# get flag
print(conn.recv(1024).decode('UTF-8'))
```
Note that conn is a type like 'string'!