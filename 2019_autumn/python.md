# Python

I use `Python 3.7.3` on `manjaro`.

## list
List can contain mutable element
### declare a list 
``` python
li = [1, 2, 3, [4, 'test for string']]
```
### add element to list 
Two method all add to the end of the list 
``` python
li.append(5)        # add as single element
li.extend([6, 7])   # add each element to list and extend the list
```
or use insert(position, value)
``` python
li.insert(3, 666)
```
### access element 
[start_index : end_index]
```python
li[3]
li[-1] # the last
li[3:5]
li[:  index] # from begin to a range
li[: -index] # from end to begin
li[ :: -1]   # reverse   
```
### remove from list 
```python
li.remove(5)
li.pop()    # remove the last one 
li.pop(3)   # remove li[3]
```
---
## tuple
immutable list
use () to declare a tuple
```python
tu = (1, 2, 3)
tuuu = ('string', ) # add a comma for clearly expression
```

---
## expression
### operator
+ `+` : 1+1
+ `-` : 3-2
+ `*` : 3*3
+ `**` : ```8**2 = 8*8 = 64```
+ `/` : 1/3 = 0.3333333
+ `//` : 1/3 = 0 // floor (a smaller integer than answer)
+ `%` : mod 7%2 = 1
### compare operator
return bool type 
+ `< <= > >= != ==` same as c
+ `in` , `not in` : check member
``` python
li = [1, 2, 3, 4, 5]
a = 3
a in li # return true
```
+ `is`, `is not` : check whether two variable point to **the same object**
``` python
a = 4
b = 1 + 3
a is b # return true
```
### logic operator
+ `and`, `or`, `not`
if you want to write `x<y and y<=z` , in python you can write `x<y<=z`
+ `None`, `False`, `0`, `""`, `empty list`, `empty tuple` will be set as **False**
### assignment 
``` python
a,b = 3, 4
[a, b] = [3, 4]
a, b = b, a     # swap in python
```
use star expression (*) for unknown length
``` python
x = [1, 2, 3, 4, 5]
head, *rest = x     # head , rest = (1, [2, 3, 4, 5])
```
#### different between `x+=y` and `x = x + y` 
if the left hand side is a mutable object, 
use `+=` will modify the object.\
if the left hand side is an immutable object, 
use `+=` will produce new object.(x = x + y)
``` python
x = y = [1, 2, 3]
x += [99, 98]   # x = y = [1, 2, 3, 99, 98]
#but if we write
x = x + [99, 98] # x = [1, 2, 3, 99, 98], but y = [1, 2, 3]
```
### if statement
``` python
if condition :
    statement
    pass # do nothing
elif condition :
    statement
    pass
else :
    pass
```
### while
``` python
while expresion :
    statement
```
### for loop
``` python
for target in expression_list:
    statement
# I think that similar to
# for (auto i : some_list) in c++

# or use range()
for x in range(0, 10) : # x = 0 ~ 9
    statement
# or jump
for x in range(0, 10, 2) : # x = 0 2 4 6 8
    statement
```
### break , continue 
same as c++

---
## function
``` python
def funcname ( parameter ) :
    return
```

---
## module
```import module_name```
if you want to use the function in this module: ```module_name.function```

``` from module_name import * ``` can directly use function , similar to ```using namespace ...```

```from module_name import some_func``` can directly use some_func , but else need to use module_name.func


```import module_name as some_name``` when use func type ```some_name.func```