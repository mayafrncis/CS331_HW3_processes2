#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
	int ret1 = fork();
	if (ret1 == 0)
		exit(0);
	int ret2 = fork();
	if (ret2 == 0)
		exit(1);
	else {
		int child1_status, child2_status;
		waitpid(ret1, &child1_status,0);
		waitpid(ret2, &child2_status,0);
		printf("Child 1 exit status: %d\n", WEXITSTATUS(child1_status));
		printf("Child 2 exit status: %d\n", WEXITSTATUS(child2_status));
		if (child1_status == 0)
			printf("Child 1 exited normally\n");
		else
			printf("Child 1 exited with an error\n");
		if (child2_status == 0)
                        printf("Child 2 exited normally\n");
                else
                        printf("Child 2 exited with an error\n");
	}
	return 0;
}
