#include <stdio.h>

int main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	const char cstr[4] = "foo";
	char *str = cstr;
	printf("%s %s\n", cstr,str);
	return 0;
}
