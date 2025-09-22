#include <stdio.h>
#include <stdlib.h>

void function1() {
	printf("Function 1 is running.\n");
}

void function2() {
	printf("Function 2 is running.\n");
}

int main() {
	atexit(function2);
	atexit(function1);
	printf("Program is runnning.\n");
	exit(0);
	printf("End of program\n");
	return 0;
}
