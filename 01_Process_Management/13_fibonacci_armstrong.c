#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int isArmstrong(int n)
{
    int temp = n, digits = 0, sum = 0;
    if (n == 0) return 1;
    while (temp > 0) {
        digits++;
        temp /= 10;
    }
    temp = n;
    while (temp > 0) {
        int digit = temp % 10;
        int power = 1;
        for (int i = 0; i < digits; i++) power *= digit;
        sum += power;
        temp /= 10;
    }
    return sum == n;
}

int main()
{
    int n;
    printf("Enter limit: ");
    scanf("%d", &n);
    if (n < 0) return 1;

    pid_t pid = fork();
    if (pid == 0) {
        int a = 0, b = 1;
        printf("Fibonacci: ");
        while (a <= n) {
            printf("%d ", a);
            int c = a + b;
            a = b;
            b = c;
        }
        printf("\n");
    }
    else if (pid > 0) {
        wait(NULL);
        printf("Armstrong numbers: ");
        for (int i = 0; i <= n; i++)
            if (isArmstrong(i)) printf("%d ", i);
        printf("\n");
    }
    else {
        perror("fork");
        return 1;
    }
    return 0;
}
