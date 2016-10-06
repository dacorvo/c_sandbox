#include <stdint.h>
#include <stdio.h>

#define Q(x) #x[0]
#define KEY(a,b,c,d) (*(int *) (char[]) {Q(a), Q(b), Q(c), Q(d)})

int main(int argc, char *argv[])
{
	uint32_t key = KEY(t,r,u,c);
	printf("Form: %d - %c %c %c %c\n",key,
		   ((char *)&key)[0],
		   ((char *)&key)[1],
		   ((char *)&key)[2],
		   ((char *)&key)[3]);
}
