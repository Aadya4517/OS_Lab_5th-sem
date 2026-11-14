#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid = fork();

    if (pid == 0) {
        printf("Odd numbers: ");
        for (int i = 1; i <= 20; i += 2)
            printf("%d ", i);
        printf("\n");
    }
    else if (pid > 0) {
        wait(NULL);
        printf("Even numbers: ");
        for (int i = 2; i <= 20; i += 2)
            printf("%d ", i);
        printf("\n");
    }
    else {
        perror("fork");
        return 1;
    }
    return 0;
}
