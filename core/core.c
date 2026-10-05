#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

#define UI_TO_CORE "fifos/ui_to_core"
#define CORE_TO_LOGGER "fifos/core_to_logger"

void execute_command(char *command)
{
    printf("[CORE] Executing: %s\n", command);

    if (strcmp(command, "start") == 0)
    {
        printf("[CORE] CPU execution started.\n");
    }
    else if (strcmp(command, "status") == 0)
    {
        printf("[CORE] CPU Status: RUNNING\n");
        printf("[CORE] Memory Status: ACTIVE\n");
        printf("[CORE] Stack Status: ACTIVE\n");
        printf("[CORE] Queue Status: ACTIVE\n");
    }
    else if (strcmp(command, "stop") == 0)
    {
        printf("[CORE] CPU execution stopped.\n");
    }
    else if (strcmp(command, "exit") == 0)
    {
        printf("[CORE] Shutting down...\n");
    }
    else
    {
        printf("[CORE] Unknown command.\n");
    }
}

int main()
{
    char command[100];
    char log_message[150];

    // Create FIFO for communication
    mkfifo(UI_TO_CORE, 0666);
    mkfifo(CORE_TO_LOGGER, 0666);

    printf("====================================\n");
    printf("          CORE PROCESS\n");
    printf("====================================\n");

    while (1)
    {
        // Open UI -> Core FIFO
        int fd = open(UI_TO_CORE, O_RDONLY);

        if (fd == -1)
        {
            perror("Error opening UI to Core FIFO");
            return 1;
        }

        // Read command from UI
        int bytes_read = read(fd, command, sizeof(command) - 1);
        close(fd);

        if (bytes_read <= 0)
        {
            continue;
        }

        command[bytes_read] = '\0';

        printf("\n[CORE] Received command: %s\n", command);

        // Execute command
        execute_command(command);

        // Prepare log message
        snprintf(log_message, sizeof(log_message),
                 "Core executed command: %s", command);

        // Send message to Logger
        int logger_fd = open(CORE_TO_LOGGER, O_WRONLY);

        if (logger_fd != -1)
        {
            write(logger_fd, log_message, strlen(log_message) + 1);
            close(logger_fd);
        }

        // Exit
        if (strcmp(command, "exit") == 0)
        {
            break;
        }
    }

    printf("\nCore Process terminated.\n");

    return 0;
}
