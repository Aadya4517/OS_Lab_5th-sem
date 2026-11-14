#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid = fork();

    if (pid == 0) {
        printf("Child is exiting now. PID = %d\n", getpid());
        return 0;
    }
    else if (pid > 0) {
        printf("Parent sleeping. Check the child using: ps -el | grep %d\n", pid);
        sleep(10);
        wait(NULL);
        printf("Parent collected the child status.\n");
    }
    else {
        perror("fork");
        return 1;
    }
    return 0;
}
