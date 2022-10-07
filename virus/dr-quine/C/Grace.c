#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#define not_a_main main
/*
	this is really not a main
*/
int not_a_main()
{
	int fd = open("Grace_kid.c", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if(fd==-1)
	{
		perror("open failed");
		exit(1);
	}
	if(dup2(fd,1)==-1)
	{
		perror("dup2 failed");
		exit(1);
	}
	char *S = "#include <stdio.h>%c#include <stdlib.h>%c#include <unistd.h>%c#include <fcntl.h>%c#define not_a_main main%c/*%c%cthis is really not a main%c*/%cint not_a_main()%c{%c%cint fd = open(%cGrace_kid.c%c, O_WRONLY | O_CREAT | O_TRUNC, 0644);%c%cif(fd==-1)%c%c{%c%c%cperror(%copen failed%c);%c%c%cexit(1);%c%c}%c%cif(dup2(fd,1)==-1)%c%c{%c%c%cperror(%cdup2 failed%c);%c%c%cexit(1);%c%c}%c%cchar *S = %c%s%c;%c%cprintf(S, 10, 10, 10, 10, 10, 10, 9, 10, 10, 10, 10, 9, 34, 34, 10, 9, 10, 9, 10, 9, 9, 34, 34, 10, 9, 9, 10, 9, 10, 9, 10, 9, 10, 9, 9, 34, 34, 10, 9, 9, 10, 9, 10, 9, 34, S, 34, 10, 9, 10);%c}";
	printf(S, 10, 10, 10, 10, 10, 10, 9, 10, 10, 10, 10, 9, 34, 34, 10, 9, 10, 9, 10, 9, 9, 34, 34, 10, 9, 9, 10, 9, 10, 9, 10, 9, 10, 9, 9, 34, 34, 10, 9, 9, 10, 9, 10, 9, 34, S, 34, 10, 9, 10);
}