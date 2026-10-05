#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

#define CORE_TO_LOGGER "fifos/core_to_logger"

void write_log(const char *message)
{
    FILE *file = fopen("execution.log", "a");

    if (file == NULL)
    {
        perror("Error opening log file");
        return;
    }

    time_t current_time = time(NULL);

    fprintf(file, "[%s] %s\n", ctime(&current_time), message);

    fclose(file);
}

int main()
{
    char message[200];

    // Create FIFO
    mkfifo(CORE_TO_LOGGER, 0666);

    printf("====================================\n");
    printf("         LOGGER PROCESS\n");
    printf("====================================\n");

    while (1)
    {
        // Open FIFO for reading
        int fd = open(CORE_TO_LOGGER, O_RDONLY);

        if (fd == -1)
        {
            perror("Error opening Logger FIFO");
            return 1;
        }

        // Read message from Core
        int bytes_read = read(fd, message, sizeof(message) - 1);

        close(fd);

        if (bytes_read <= 0)
        {
            continue;
        }

        message[bytes_read] = '\0';

        printf("[LOGGER] %s\n", message);

        // Save message to log file
        write_log(message);

        // Stop Logger when Core sends exit
        if (strstr(message, "exit") != NULL)
        {
            break;
        }
    }

    printf("\nLogger Process terminated.\n");

    return 0;
}
