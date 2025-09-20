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
	if (ret2 == 0)
		printf("2nd Child PID: %d\n", getpid());
	else {
		int exitStatus_child2, exitStatus_child1;
		waitpid(ret2, &exitStatus_child2,0); //waited for child2 first, in case it waits on child 2 when I use wait(NULL instead of 1, which would mean child 1 wouldnt be waited for
		wait(&exitStatus_child1);
                printf("Parent PID: %d\n", getpid());
		printf("Exit status of child 1: %d\n", exitStatus_child1);
		printf("Exit status of child 2: %d\n", exitStatus_child2);
        }
	return 0;
}
