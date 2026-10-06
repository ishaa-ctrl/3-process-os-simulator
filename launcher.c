#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    printf("========================================\n");
    printf("   3-PROCESS OS SIMULATOR LAUNCHER\n");
    printf("========================================\n");

    pid_t logger_pid = fork();

    if (logger_pid == 0)
    {
        execl("./logger/logger", "./logger/logger", NULL);
        perror("Failed to start Logger");
        exit(1);
    }

    sleep(1);

    pid_t core_pid = fork();

    if (core_pid == 0)
    {
        execl("./core/core", "./core/core", NULL);
        perror("Failed to start Core");
        exit(1);
    }

    sleep(1);

    pid_t ui_pid = fork();

    if (ui_pid == 0)
    {
        execl("./ui/ui", "./ui/ui", NULL);
        perror("Failed to start UI");
        exit(1);
    }

    waitpid(ui_pid, NULL, 0);
    waitpid(core_pid, NULL, 0);
    waitpid(logger_pid, NULL, 0);

    printf("\nAll processes terminated successfully.\n");

    return 0;
}
