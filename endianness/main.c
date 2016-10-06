#include <stdio.h>
#include <stdlib.h>

const int i = 0x00000001;
#define is_bigendian() ( (*(char*)&i) == 0x0000 )
#define is_littleendian() ( (*(char*)&i) == 0x0001 )

int main(int argc, char* argv[]) {
    int val;
    char *ptr;
    ptr = (char*) &val;
    val = 0x12345678;
    if (is_bigendian()) {
        printf("BIG\n");
        printf("%X.%X.%X.%X\n", ptr[0], ptr[1], ptr[2], ptr[3]);
    } else if (is_littleendian()) {
        printf("LITTLE\n");
        printf("%X.%X.%X.%X\n", ptr[3], ptr[2], ptr[1], ptr[0]);
    } else {
    	printf("Unknown endianness\n");
	}
    exit(0);
}
