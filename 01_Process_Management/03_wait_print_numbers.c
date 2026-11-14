#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid = fork();

    if (pid == 0) {
        for (int i = 1; i <= 5; i++)
            printf("Child: %d\n", i);
    }
    else if (pid > 0) {
        wait(NULL);
        printf("Parent: child has finished\n");
    }
    else {
        perror("fork");
        return 1;
    }
    return 0;
}
