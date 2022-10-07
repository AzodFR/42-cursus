#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main() {
	char filename[10];
	char cmd[66];
	int i = 5;
	sprintf(filename, "Sully_%d.c", --i);
	int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	char *S = "#include <stdio.h>%c#include <stdlib.h>%c#include <unistd.h>%c#include <fcntl.h>%c#include <string.h>%c%cint main() {%c%cchar filename[10];%c%cchar cmd[66];%c%cint i = %d;%c%csprintf(filename, %cSully_%%d.c%c, --i);%c%cint fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);%c%cchar *S = %c%s%c;%c%cdprintf(fd, S, 10, 10, 10, 10, 10, 10, 10, 9, 10, 9, 10, 9, i, 10, 9, 34, 34, 10, 9, 10, 9, 34, S, 34, 10, 9, 10, 9, 10, 9, 9, 34, 34, 10, 9, 10, 9, 9, 34, 34, 10, 9, 10);%c%cif(i)%c%c%csprintf(cmd, %cclang -Wall -Wextra -Werror %%s -o Sully_%%d; ./Sully_%%d%c, filename, i, i);%c%celse%c%c%csprintf(cmd, %cclang -Wall -Wextra -Werror %%s -o Sully_%%d%c, filename, i);%c%csystem(cmd);%c}";
	dprintf(fd, S, 10, 10, 10, 10, 10, 10, 10, 9, 10, 9, 10, 9, i, 10, 9, 34, 34, 10, 9, 10, 9, 34, S, 34, 10, 9, 10, 9, 10, 9, 9, 34, 34, 10, 9, 10, 9, 9, 34, 34, 10, 9, 10);
	if(i)
		sprintf(cmd, "clang -Wall -Wextra -Werror %s -o Sully_%d; ./Sully_%d", filename, i, i);
	else
		sprintf(cmd, "clang -Wall -Wextra -Werror %s -o Sully_%d", filename, i);
	system(cmd);
}