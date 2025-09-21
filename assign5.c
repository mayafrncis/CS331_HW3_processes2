#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
	int ret = fork();
	if (ret == 0) {
		printf("Hello from the child with PID: %d\n", getpid());
		exit(0);
	} else {
		printf("Parent PID: %d\n", getpid());
		sleep(30);
	}
	return 0;
}
