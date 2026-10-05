#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

#define FIFO_PATH "fifos/ui_to_core"
#define CORE_TO_UI "fifos/core_to_ui"

int main()
{
    char command[100];

    // Create FIFO if it doesn't already exist
    mkfifo(FIFO_PATH, 0666);

    printf("====================================\n");
    printf("     3-PROCESS OS SIMULATOR\n");
    printf("====================================\n");

    printf("Enter commands for the simulator.\n");
    printf("Type 'exit' to stop.\n\n");

    while (1)
    {
        printf("Enter command: ");
        fgets(command, sizeof(command), stdin);

        // Remove newline
        command[strcspn(command, "\n")] = '\0';

        // Open FIFO for writing
        int fd = open(FIFO_PATH, O_WRONLY);

        if (fd == -1)
        {
            perror("Error opening FIFO");
            return 1;
        }

        // Send command to Core Process
        write(fd, command, strlen(command) + 1);

        close(fd);

        //recieve responds from core process
        int response_fd = open(CORE_TO_UI,O_RDONLY);

        if (response_fd == -1)
        {
            perror("Error opening Core-to-UI FIFO");
            return 1;

        }

        char response[200];

        read(response_fd, response,sizeof(response));

        printf("[CORE RESPONSE] %s\n", response);

        close(response_fd);

        // Stop UI
        if (strcmp(command, "exit") == 0)
        {
            break;
        }
    }

    printf("\nUI Process terminated.\n");

    return 0;
}
