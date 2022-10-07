#include <stdio.h>
/*
	First comment
*/

int bestSchool()
{
	return (42);
}

int main()
{
	/*
		Second comment
	*/
	char *S = "#include <stdio.h>%c/*%c%cFirst comment%c*/%c%cint bestSchool()%c{%c%creturn (42);%c}%c%cint main()%c{%c%c/*%c%c%cSecond comment%c%c*/%c%cchar *S = %c%s%c;%c%cprintf(S, 10, 10, 9, 10, 10, 10, 10, 10, 9, 10, 10, 10, 10, 10, 9, 10, 9, 9, 10, 9, 10, 9, 34, S, 34, 10, 9, 10, 9, 10);%c%cbestSchool();%c}";
	printf(S, 10, 10, 9, 10, 10, 10, 10, 10, 9, 10, 10, 10, 10, 10, 9, 10, 9, 9, 10, 9, 10, 9, 34, S, 34, 10, 9, 10, 9, 10);
	bestSchool();
}