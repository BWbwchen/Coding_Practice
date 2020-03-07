# picobrowser

website say : 
```
You're not picobrowser! Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/80.0.3987.122 Safari/537.36
```

so I try to modified cookie
```
User-Agent:picobrowser
```

but it doesn't work, I check the request header and I see the original User-Agent still not change.

So I need to modifiy the request header

## Solve

use `curl` 's -A option