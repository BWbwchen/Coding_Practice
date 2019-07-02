# Mistake
He say the hint is operator priority.
```c
#include <stdio.h>
#include <fcntl.h>

#define PW_LEN 10
#define XORKEY 1

void xor(char* s, int len){
	int i;
	for(i=0; i<len; i++){
		s[i] ^= XORKEY;
	}
}

int main(int argc, char* argv[]){
	
	int fd;
	if(fd=open("/home/mistake/password",O_RDONLY,0400) < 0){
		printf("can't open password %d\n", fd);
		return 0;
	}

	printf("do not bruteforce...\n");
	sleep(time(0)%20);

	char pw_buf[PW_LEN+1];
	int len;
	if(!(len=read(fd,pw_buf,PW_LEN) > 0)){
		printf("read error\n");
		close(fd);
		return 0;		
	}

	char pw_buf2[PW_LEN+1];
	printf("input password : ");
	scanf("%10s", pw_buf2);

	// xor your input
	xor(pw_buf2, 10);

	if(!strncmp(pw_buf, pw_buf2, PW_LEN)){
		printf("Password OK\n");
		system("/bin/cat flag\n");
	}
	else{
		printf("Wrong Password\n");
	}

	close(fd);
	return 0;
}
```

After see the code, I found that the suspicious part is compare in the if statement.
```c
if(fd=open("/home/mistake/password",O_RDONLY,0400) < 0)
```
see this first : [`operator precedence`](https://en.cppreference.com/w/c/language/operator_precedence)

We know that computer will do compare with 0 first, it will get `0`.
```c
if (fd = 0) {}
```
If you write this way it will do:
```c
fd = 0
if(fd) {}
```
So `fd` is `0`, for [`linux file descriptor`](https://www.wikiwand.com/en/File_descriptor) it represent `stdin` !!!\
It means that you can input the password !!!

## Solve it !
I use `0000000000` as password. `'0'` is `110000` after xor with `1` it will become `110001`(49) !
