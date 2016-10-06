#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int
main(void)
{
	struct __attribute__((__packed__)) s {
		int i;
		char c;
		int d;
		char a[]; /* C99 flexible array member, using a pointer will segfault */
	};

	/* Output is compiler dependent */

	printf("offsets: i=%ld; c=%ld; d=%ld a=%ld\n",
		   (long) offsetof(struct s, i),
		   (long) offsetof(struct s, c),
		   (long) offsetof(struct s, d),
		   (long) offsetof(struct s, a));
	printf("sizeof(struct s)=%ld\n", (long) sizeof(struct s));

	int nb = 4;
	struct s* test = (struct s*)malloc(sizeof(struct s) + nb);
	test->i = 0x3E3E3E3E; // >>>>
	test->c = '|';
	test->d = 0x3C3C3C3C;
	test->a[0] = 'a';
	test->a[1] = 'b';
	test->a[2] = 'c';
	//test->a[3] = 'd';

	char *p = (char *)test;
	for(unsigned int i=0; i < sizeof(struct s) + nb;i++) {
		printf("[%d] %c\n",i,p[i]);
	}

	exit(EXIT_SUCCESS);
}

