# Python

I use Python 3.7.3 on manjaro.

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