# cmd2
``` c
#include <stdio.h>
#include <string.h>

int filter(char* cmd){
        int r=0;
        r += strstr(cmd, "=")!=0;
        r += strstr(cmd, "PATH")!=0;
        r += strstr(cmd, "export")!=0;
        r += strstr(cmd, "/")!=0;
        r += strstr(cmd, "`")!=0;
        r += strstr(cmd, "flag")!=0;
        return r;
}

extern char** environ;
void delete_env(){
        char** p;
        for(p=environ; *p; p++) memset(*p, 0, strlen(*p));
}

int main(int argc, char* argv[], char** envp){
        delete_env();
        putenv("PATH=/no_command_execution_until_you_become_a_hacker");
        if(filter(argv[1])) return 0;
        printf("%s\n", argv[1]);
        system( argv[1] );
        return 0;
}
```

In brief, you can't use `/bin/cat` anymore QQ

## solution 
we can't use cat because it is not builtin command in shell, so can we use the builtin command to print out the content of flag ? Unforturntely I didn't find any command QQ

But ! If we look in the builtin command of shell, we can find an interesting command `command`! 

```
The  command  utility  shall  cause the shell to treat the arguments as a simple command

−p        Perform the command search using a default value for PATH that is guaranteed to
          find all of the standard utilities.
```
Bingo ! just use `command -p cat *`

## murmur

It is toooooo hard to find a little command in such huge man page...
It take half day to find that .... without any hint ...