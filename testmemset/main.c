#include <memory.h>

struct foo {
	int bar;
	int baz;
};

struct foo qux[4];

int main(int argc, char *argv[]) {

	(void)argc;
	(void)argv;

	struct foo *foo_p = &qux[0];
	memset((void*)&qux[0],0,sizeof(struct foo));
	memset(foo_p,0,sizeof(struct foo));

}
