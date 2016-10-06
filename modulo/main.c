#include <stdio.h>

int main(int argc, char* argv[])
{
	int i,n = 12;
	for (i=0;i<n*2;i++) {
		printf("%d mod %d = %d\n",i,n,i%n);
	}
}
