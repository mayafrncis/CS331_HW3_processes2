#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main() {
	int ret = fork();
	if (ret == 0) {
		printf("Child PID: %d\n", getpid());
		exit(0);
	}
	int ret2 = fork();
	if (ret2 == 0) {
		printf("2nd Child PID: %d\n", getpid());
		exit(0);
	} else {
		int exitStatus_child2, exitStatus_child1;
		waitpid(ret2, &exitStatus_child2,0);
		wait(&exitStatus_child1);
		printf("Parent PID: %d\n", getpid());
		if (WIFEXITED(exitStatus_child1) & WIFEXITED(exitStatus_child2)) {
			printf("Exit status of child 1: %d\n", WEXITSTATUS(exitStatus_child1));
			printf("Exit status of child 2: %d\n", WEXITSTATUS(exitStatus_child2));
        	}
	}
	return 0;
}
