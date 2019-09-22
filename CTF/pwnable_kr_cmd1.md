# cmd1
``` c
#include <string.h>

int filter(char* cmd){
	int r=0;
	r += strstr(cmd, "flag")!=0;
	r += strstr(cmd, "sh")!=0;
	r += strstr(cmd, "tmp")!=0;
	return r;
}
int main(int argc, char* argv[], char** envp){
	putenv("PATH=/thankyouverymuch");
	if(filter(argv[1])) return 0;
	system( argv[1] );
	return 0;
}
```

## notice
1. in the executable we can't use cat directly, cause the path of the executable had been modify so computer can find where the `cat` is. \
So use the `/bin/cat` instead
2. in the argument , you can't use word like `flag`, `sh`, `tmp`...

## solution
how to let computer execute `cat flag` is a bog problem.
We can't use word `flag` directly.

If you try to use 
```
> cat *
```
you will know how to deal with this problem!