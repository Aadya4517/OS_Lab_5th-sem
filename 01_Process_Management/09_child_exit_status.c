#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid = fork();

    if (pid == 0) {
        printf("Child is exiting with status 10\n");
        return 10;
    }
    else if (pid > 0) {
        int status;
        wait(&status);
        if (WIFEXITED(status))
            printf("Child exit status = %d\n", WEXITSTATUS(status));
    }
    else {
        perror("fork");
        return 1;
    }
    return 0;
}
