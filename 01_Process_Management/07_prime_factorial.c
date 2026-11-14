#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int n, prime = 1;
    long long fact = 1;
    printf("Enter a number: ");
    scanf("%d", &n);

    if (n < 0 || n > 20) {
        printf("Enter a number between 0 and 20.\n");
        return 1;
    }

    pid_t pid = fork();
    if (pid == 0) {
        if (n < 2) prime = 0;
        for (int i = 2; i * i <= n; i++)
            if (n % i == 0) prime = 0;
        if (prime) printf("%d is prime\n", n);
        else printf("%d is not prime\n", n);
    }
    else if (pid > 0) {
        for (int i = 1; i <= n; i++)
            fact *= i;
        printf("Factorial = %lld\n", fact);
        wait(NULL);
    }
    else {
        perror("fork");
        return 1;
    }
    return 0;
}
