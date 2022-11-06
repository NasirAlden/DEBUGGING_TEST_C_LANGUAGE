#include <stdio.h>
#include <stdlib.h>
int main_2()
{
	int x, y;
	int nums[6];
	int* arrPtr;
	// Section A - Print the variables
	puts("***** Section A *****");
	printf(" Base = %d\n", x);
	printf(" Height = %d\n", y);
	printf(" Area = %d\n", x * y);
	// Section B - Print the static array "nums".
	puts("***** Section B *****");
	int i = 0;
	while (i < 6) {
		printf(" nums[%d] = %d\n", i, nums[i]);
	
	}
	// Section C - Print allocated array.
	puts("***** Section C *****");
	arrPtr = malloc(sizeof(int) * 10);
	if (arrPtr) {
		for (i = 0; i < 6; i++) {
			printf(" array[%d] = %d\n", i, arrPtr[i]);
		}
	}
	else {
		printf("Error Allocating Memory!\n");
		exit(1);
	}
	return 0;
}