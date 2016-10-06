#include <stdio.h>

#define UUID(...) {__VA_ARGS__,0x00}

int main(int argc, void *argv[])
{
	char uuid[6] = UUID('I','N','T','E','L');
	printf("%s\n",uuid);
}
